# Hadamard Matrix Checker
This project was made to meet the needs of a mathematician requiring  an automated program to verify specific properties of Hadamard matrices.

The process follows these steps:

- Choose the size of our matrix, given it must have size 2^n.
- Generate a permutation of the values from 0 to 2^n.
- Calculate each cell value. For each position *(i,j)* in the matrix:
  - Obtain two vectors with the binary representations of *i* and *permutation[j]*.
  - Calculate the dot product of these vectors (*i·permutation[j]*).
  - Set the cell value with *-1^(i·permutation[j])*.
- Transpose the matrix.
- Multiply the original matrix by its transpose.
- Ensure that the result is 2^n times the Identity matrix.

This project has been proven valuable to the mathematician while also providing me with an opportunity to learn the fundamentals of C++ and explore its applications in mathematical programming.
