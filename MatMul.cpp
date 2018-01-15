#include <string>
#include "MatrixOps.h"

/** A simple matrix multiplication program.

    This program has been designed to provide a very simple matrix
    multiplication program for benchmarking etc.

    Copyright (C) 2016 raodm@miamiOH.edu
*/


// Convenience method to do matrix multiplication on fixed size
// matrices using either regular or Block matrix multiplication
void fixedSizeTest(const int size, const size_t blockSize = 0) {
    // Print message on the test being conducted:
    std::cout << "Multiplying matrices of size: " << size << " using ";
    if (blockSize == 0) {
        std::cout << "regular matrix multiplication.\n";
    } else {
        std::cout << "block multiplication, block size: " << blockSize
                  << std::endl;
    }
    // Create 2 matrices of specified size
    const Matrix mat1 = initMatrix(size, size);
    const Matrix mat2 = initMatrix(size, size);
    // Perform matrix multiplication
    if (blockSize > 0) {
        const Matrix mat3 = blockMultiply(mat1, mat2, blockSize);
        // Print result.
        std::cout << "Diag sum: " << sumDiag(mat3) << std::endl;
    } else {
        const Matrix mat3 = multiply(mat1, mat2);
        // Print result.
        std::cout << "Diag sum: " << sumDiag(mat3) << std::endl;
    }
}

void fileBasedTest(const std::string& mat1File, const std::string& mat2File,
                   const std::string& mat3File, const size_t blockSize = 0) {
    // Load the files...
    const Matrix mat1 = load(mat1File);
    const Matrix mat2 = load(mat2File);
    // Print message on the test being conducted:
    std::cout << "Multiplying matrices from files: " << mat1File << " and "
              << mat2File << " using ";
    // Perform matrix multiplication
    if (blockSize > 0) {
        std::cout << "block multiplication, block size: " << blockSize
                  << std::endl;
        const Matrix mat3 = blockMultiply(mat1, mat2, blockSize);
        write(mat3File, mat3);
        // Print result.
        std::cout << "Diag sum: " << sumDiag(mat3) << std::endl;
    } else {
        std::cout << "regular matrix multiplication.\n";
        const Matrix mat3 = multiply(mat1, mat2);
        write(mat3File, mat3);
        // Print result.
        std::cout << "Diag sum: " << sumDiag(mat3) << std::endl;
    }
}

int main(const int argc, char *argv[]) {
    if (argc == 3) {
        // Test fixed size matrix
        fixedSizeTest(std::stoi(argv[1]), std::stoi(argv[2]));
    } else if (argc == 5) {
        // Test file-based matrix data operation
        fileBasedTest(argv[1], argv[2], argv[3], std::stoi(argv[4]));
    } else {
        std::cerr << "Specify one of the following 2 sets of parameters:\n";
        std::cerr << "Example #1: " << argv[0] << " <InputMatFile #1> "
                  << "<InputMatFile #2> <OutputMatFile #3> <BlockSize>\n"
                  << "Example #2: " << argv[0] << " <MatSize> <BlockSize>\n";
        return 1;
    }
    return 0;
}

// End of source code.
