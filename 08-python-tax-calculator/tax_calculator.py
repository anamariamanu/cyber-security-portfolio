"""
Commercia tax calculation system.

Takes employee details, works out income tax using simplified bands
from the assignment brief, and prints a payslip for each employee.
"""


# Function to print the payslip
def print_payslip(Full_name, Organisation, income, tax_band, tax_value, net_pay):
    """
    Prints the employee's payslip with details.

    Parameters:
        Full_name (str): The full name of the employee.
        Organisation (str): The organisation the employee works for.
        income (float): The employee's income.
        tax_band (str): The tax band based on the employee's income.
        tax_value (float): The calculated tax amount.
        net_pay (float): The employee's net pay after tax deduction.
    """
    print("\n----* Commercia Payslip *----")
    print(f"Employee Name: {Full_name}")
    print(f"Organisation: {Organisation}")
    print(f"Income: £{income:.2f}")
    print(f"Tax Band: {tax_band}")
    print(f"Income Tax: £{tax_value:.2f}")
    print(f"Net Pay: £{net_pay:.2f}")
    print("---------------------------\n")


# Main function to run the program
def main():
    """
    Main function to run the tax calculation system.
    Takes employee details as input, calculates tax, and prints the payslip.
    Allows the user to add multiple employees.
    """
    print("Welcome to the Tax calculation system!")

    while True:
        # Ask for the employee's details
        Full_name = input("Enter employee's full name: ")
        Organisation = input("Enter the organisation: ")
        income = float(input("Enter the employee's income: "))

        # Calculate the tax based on income
        if income <= 20000:
            tax_value = 0
            tax_band = "Personal allowance"
        elif 20000 < income < 100000:
            tax_value = 0.2 * (income - 20000)
            tax_band = "Basic rate"
        else:
            tax_value = 0.45 * (income - 100000) + 0.2 * (100000 - 20000)
            tax_band = "Additional rate"

        # Calculate net pay
        net_pay = income - tax_value

        # Print the payslip
        print_payslip(Full_name, Organisation, income, tax_band, tax_value, net_pay)

        # Ask if the user wants to add another employee
        another = input("Do you want to add another employee? (yes/no): ").strip().lower()
        if another != 'yes':
            break

    print("Thank you for using the Tax Calculation System!")


# Run the program
if __name__ == "__main__":
    main()
