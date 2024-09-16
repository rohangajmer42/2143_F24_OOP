# 06-P01 - Fraction Calculator
### Rohan Gajmer

### Description:
This project is a **Fraction Calculator** that takes two fractions and an operator as input, performs the desired arithmetic operation (addition, subtraction, multiplication, or division), and prints the result as a fraction. The program uses overloaded operators in C++ to handle the arithmetic operations and simplifies the result if necessary.

## Features

- Supports fractions inputted in the format `n/d` where `n` is the numerator and `d` is the denominator.
- Can handle the following arithmetic operations:
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Division (`/`)
- Accepts input from standard input (keyboard or file redirection).

### Files

|   #   | File            | Description                                              |
| :---: | --------------- | -------------------------------------------------------- |
|   1   | [main.cpp](main.cpp)        | Main driver file that contains the Fraction class and logic to perform operations on fractions. |
|   2   | [data](data)            | Example input file containing fractions and operators to test the calculator. |
|   3   | [output.txt](output.txt)      | Code given output. |


+------------+  
| n1/d1 op n2/d2 |  
+------------+

Where:
- `n1/d1` is the first fraction.
- `op` is the operator (`+`, `-`, `*`, `/`).
- `n2/d2` is the second fraction.
