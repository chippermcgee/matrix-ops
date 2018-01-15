// Copyright (C) 2016 raodm@miamiOH.edu

#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include "MatrixOps.h"

using namespace std;

// Initializes a matrix of a given size. 
Matrix initMatrix(const size_t rows, const size_t cols) {
    Matrix mat(rows, std::vector<Val>(cols));
    for (size_t row = 0; (row < rows); row++) {
        for (size_t col = 0; (col < cols); col++) {
            mat[row][col] = row + col;
        }
    }
    return mat;
}
    
Matrix multiply(const Matrix& matrix1, const Matrix& matrix2) {
    const size_t cols  = matrix2[0].size();
    Matrix matrix3(matrix1.size(), std::vector<Val>(cols));
    for (size_t row = 0; (row < matrix1.size()); row++) {
        for (size_t col = 0; (col < cols); col++) {
            Val sum = 0;
            const size_t rows2 = matrix2.size();
            for (size_t i = 0; (i < rows2); i++)  {
                sum += (matrix1[row][i] * matrix2[i][col]);
            }
            matrix3[row][col] = sum;
        }
    }
    return matrix3;
}

Val sumDiag(const Matrix& mat) {
    Val sum = 0;
    size_t minDim = std::min(mat.size(), mat[0].size());
    for (size_t i = 0; (i < minDim); i++) {
        sum += mat[i][i];
    }
    return sum;
}

Matrix myInitMatrix(const size_t rows, const size_t cols) {
    Matrix mat(rows, std::vector<Val>(cols, 0.0));
    return mat;
}

Matrix blockMultiply(const Matrix& matrix1, const Matrix& matrix2,
                            const size_t blockSize) {
    // The reason I initialize all three of those is that in case the matrices
    // are not square, the size bounds need to be treated differently.
    // I had to illustrate the entire algorithm for this.
    size_t r1 = matrix1.size();  // r1 is the bound for i
    size_t r2 = matrix2.size();  // r2 is num rows for matrix2, relates to kk&k
    size_t c2 = matrix2[0].size();  // c2 is num cols for matrix2, relates to jj
    Matrix matrix3 = myInitMatrix(r1, c2);
    for (size_t jj = 0; jj < c2; jj += blockSize) {
        for (size_t kk = 0; kk < r2; kk += blockSize) {
            for (size_t i = 0; i < r1; i++) {
                for (size_t j = jj; j < min(c2, (jj+blockSize)); j++) {
                    double tmp = 0;
                    for (size_t k = kk; k < min(r2, (kk+blockSize)); k++) {
                        tmp += matrix1[i][k] * matrix2[k][j];
                    }
                    matrix3[i][j] += tmp;
                }
            }
        }
    }
    return matrix3;
}

void write_cout(const Matrix& mat) {
    size_t rows = mat.size();
    size_t cols = mat[0].size();
    std::cout << "Rows/Columns: " << rows << " " << cols << std::endl;
    for (size_t i = 0; i < rows; i++) {
        for (double j : mat[i]) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

Matrix load(const std::string& filePath) {
    size_t r, c;
    ifstream fin(filePath);
    fin >> r >> c;
    Matrix mat(r, std::vector<Val>());
    for (size_t i = 0; i < r; i++) {
        for (size_t j = 0; j < c; j++) {
            double d;
            fin >> d;
            mat[i].push_back(d);
        }
    }
    // write_cout(mat);
    return mat;
}

void write(const std::string& filePath, const Matrix& mat) {
    ofstream fout(filePath);
    size_t rows = mat.size();
    size_t cols = mat[0].size();
    fout << rows << " " << cols << std::endl;
    for (size_t i = 0; i < rows; i++) {
        std::string line;
        for (double j : mat[i]) {
            fout << j << " ";
        }
        fout << line << std::endl;
    }
    // write_cout(mat);
}
