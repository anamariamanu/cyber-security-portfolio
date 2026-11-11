# Python Tax Calculator

**Grade: Distinction** · Unit 4: Programming · 2025

A command-line program for Commercia (fictional). It takes each employee's details, calculates income tax and prints a payslip, and it can process several employees in one run.

## Run it

```bash
python tax_calculator.py
```

Example output:

```
----* Commercia Payslip *----
Employee Name: Jane Smith
Organisation: Commercia
Income: £45000.00
Tax Band: Basic rate
Income Tax: £5000.00
Net Pay: £40000.00
---------------------------
```

## Tax bands (simplified, from the assignment brief)

| Income | Band | Rate |
|---|---|---|
| Up to £20,000 | Personal allowance | 0% |
| £20,000–£100,000 | Basic rate | 20% above £20,000 |
| Over £100,000 | Additional rate | 45% above £100,000 |

## What the report covered

- Algorithms and pseudocode for the tax logic
- Procedural, object-oriented and event-driven programming compared
- Debugging in an IDE (Visual Studio Code), with breakpoints and watch variables
- Coding standards: naming, comments and docstrings

## Ideas to improve it

- Validate input so a typo in the income doesn't crash the program
- Move the tax bands into one table so they're easy to update
- Add unit tests for each tax band

## Skills shown

Python · functions and docstrings · control flow · debugging · coding standards
