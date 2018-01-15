// Copyright (C) 2016 raodm@miamiOH.edu

#ifndef MATRIX_OPS_H
#define MATRIX_OPS_H

#include <iostream>
#include <vector>
#include <string>

/** A simple matrix multiplication program.

    This program has been designed to provide a very simple matrix
    multiplication program for benchmarking etc.

    Copyright (C) 2016 raodm@miamiOH.edu
*/

// Shortcut for the value of each element in the matrix
using Val = double;

// Short cut to a 2-d vector double values to streamline the code
using Matrix = std::vector<std::vector<Val>>;

// External definition for blockMultiply method with 3 parameters. See
// documentation for details.
Matrix blockMultiply(const Matrix& matrix1, const Matrix& matrix2,
                            const size_t blockSize);

// Method to load matrix from a given data file. See documentation for
// details.
Matrix load(const std::string& filePath);

// Method to write matrix to a given file.
void write(const std::string& filePath, const Matrix& mat);

// Method to create an initialize 
Matrix initMatrix(const size_t rows, const size_t cols);

// Method to perform standard matrix multiplication with O(n^3)
// routine.
Matrix multiply(const Matrix& matrix1, const Matrix& matrix2);

// Method for diagonal sum.
Val sumDiag(const Matrix& mat);

#endif
