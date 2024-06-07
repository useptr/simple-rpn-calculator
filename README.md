# Simple RPN (reverse polish notation) calculator

## Introduction

RPN (reverse polish notation) Calculator in C++20

This project is a C++ implementation of a Reverse Polish Notation (RPN) calculator. The calculator reads arithmetic expressions, converts them from infix notation to postfix notation (RPN), and evaluates the result.

![calculator app](/misc/images/example.png)
## Information

Note that you should use *Dijkstra's algorithm* to translate expressions into *reverse Polish notation* to implement the calculator. You can find all the necessary information in the SmartCalc v1.0 project description to refresh your knowledge.

## Supported operators
   - **Arithmetic operators**:
     | Operator name | Operator | 
      | --------- | ------ |
      | Brackets | (x + y) |
      | Addition | x + y | 
      | Subtraction | x - y | 
      | Multiplication | x * y | 
      | Division | x / y | 
      | Power | x ^ y | 
      | Modulus | x mod y |
      | Unary plus | +x | 
      | Unary minus | -x | 
   - **Functions**:
      | Function name | Function |
      | ------ | ------ |
      | Computes cosine | cos(x) |
      | Computes sine | sin(x) |
      | Computes tangent | tan(x) |
      | Computes arc cosine | acos(x) |
      | Computes arc sine | asin(x) |
      | Computes arc tangent | atan(x) |
      | Computes square root | sqrt(x) |
      | Computes natural logarithm | ln(x) |
      | Computes common logarithm | log(x) |

## How to run
```
% make install
```