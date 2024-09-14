# Arithmetic Calculator

## Author

- **Gabriel Cesar Silvino Xavier**

## University

This project was developed for the **Computer Programming I** course in the **Computer Science** program, under the guidance of Professor **Daniel Saad Nogueira Nunes**.

## Overview

Welcome to the **Arithmetic Calculator** project. This project consists of a **C language program** that performs basic mathematical operations: addition, subtraction, and multiplication. This README provides detailed information on how to compile and run the program, as well as explaining its features and usage.

## Features

The project includes:

### Simple Calculator

A program that allows the user to perform mathematical operations with two operands. The supported operations are:

- Addition
- Subtraction
- Multiplication

## Usage

The program follows this input format:

1. **Number of operations**: Indicates how many operations the user wants to perform.
2. **First operand**: The value of the first number.
3. **Second operand**: The value of the second number.
4. **Operation**: The type of operation to be performed (1 = addition, 2 = subtraction, 3 = multiplication).

### Example Input Format:

```
a b x
```

- `a` = First operand
- `b` = Second operand
- `x` = Operation type (1 for addition, 2 for subtraction, 3 for multiplication)

## Compilation and Execution

Follow these steps to compile and run the program:

1. **Compile the program**:

   In the terminal, run the following command to compile the program:

   ```bash
   gcc main.c -o ArithmeticCalculator
   ```

2. **Run the program**:

   After compiling, run the program with the command:

   ```bash
   ./ArithmeticCalculator
   ```

