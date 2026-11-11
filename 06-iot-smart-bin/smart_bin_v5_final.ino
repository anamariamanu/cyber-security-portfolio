// IoT Smart Waste Bin - Iteration 5 (final)
// Arduino Uno + HC-SR04 ultrasonic sensor + SG90 servo
//
// Changes from the baseline, each driven by user feedback:
//   Iteration 2: trigger distance 50 cm -> 40 cm (fewer false triggers)
//   Iteration 3: lid-open time 3000 ms -> 5000 ms (more time to use the bin)
//   Iteration 4: average of 10 readings instead of 3 (more stable sensor)
//   Iteration 5: Serial logging for test records, shorter servo delay and
//                slower polling to reduce battery drain

#include <Servo.h>   // servo library

Servo servo;
int trigPin = 5;
int echoPin = 6;
int servoPin = 7;
int led = 10;
long duration, dist, average;
long aver[10];       // ITERATION 4: room for 10 readings

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.write(0);     // close cap on power on
  delay(100);
  servo.detach();
}

void measure() {
  digitalWrite(10, HIGH);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  dist = (duration / 2) / 29.1;   // obtain distance in cm
}

void loop() {
  // ITERATION 4: take 10 readings
  for (int i = 0; i < 10; i++) {
    measure();
    aver[i] = dist;
    delay(10);
  }

  dist = (aver[0] + aver[1] + aver[2] + aver[3] + aver[4] +
          aver[5] + aver[6] + aver[7] + aver[8] + aver[9]) / 10;

  // ITERATION 5: logging
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.print(" cm | Trigger: ");
  Serial.println(dist < 40 ? "YES" : "NO");

  // ITERATION 2: changed detection distance
  if (dist < 40) {    // changed from 50 cm
    servo.attach(servoPin);

    // ITERATION 3: increased lid-open time
    servo.write(0);
    delay(5000);      // changed from 3000 ms

    servo.write(150);
    delay(300);       // reduced for battery saving (iteration 5)

    servo.detach();
  }

  // ITERATION 5: reduced polling
  delay(80);
}
