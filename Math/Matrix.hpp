/**
 * @file Matrix.hpp
 *
 * Header file for the Matrix class
 *
 * Copyright (c) 2023 Kevin Lou
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef LOULIB_MATRIX_HPP
#define LOULIB_MATRIX_HPP

#include <vector>
#include "Vector.hpp"
#include <stdexcept>

namespace LouLib {
    namespace Math {

        /**
         * @class Matrix
         * @brief Class representing a mathematical matrix
         */
        class Matrix {
        private:
            class MatrixRow{
            private:
                std::vector<double> data;

            public:
                /**
                 * Constructs a new matrix row of the given size
                 */
                explicit MatrixRow(int n);

                /**
                 * Constructs a new matrix row with the given data
                 */
                MatrixRow(std::initializer_list<double> rowData);

                /**
                 * Constructs a new matrix row with the given data
                 */
                explicit MatrixRow(std::vector<double> rowData);

                /**
                 * Constructs a new matrix row that is a copy of the given row
                 */
                MatrixRow(const MatrixRow& other);

                /**
                 * Operator to get a reference to the element at the specified index
                 * @throws std::invalid_argument if the index does not exist
                 */
                double& operator[](int i);

                /**
                 * Operator to get a const reference to the element at the specified index
                 * @throws std::invalid_argument if the index does not exist
                 */
                const double& operator[](int i) const;

                /**
                 * Returns the number of elements in the matrix row
                 */
                int size() const;

                /**
                 * Returns the row as a Vector
                 */
                 Vector getVector();
            };

            std::vector<MatrixRow> data;

        public:
            /**
             * Constructs a new matrix of the given dimensions
             * @param rows Number of rows
             * @param cols Number of columns
             */
            Matrix(int rows, int cols);

            /**
             * Constructs a new matrix with the given data
             * @param matrixData matrix data
             */
            Matrix(std::initializer_list<std::initializer_list<double>> matrixData);

            /**
             * Constructs a new matrix with the given data
             * @param matrixData matrix data
             */
            Matrix(std::vector<std::vector<double>> matrixData);

            /**
             * Constructs a new matrix with the given data
             * @param matrixData matrix data
             */
            Matrix(std::vector<MatrixRow> matrixData);

            /**
             * Constructs a new matrix that is a copy of the given matrix
             * @param other The Matrix to be copied
             */
            Matrix(const Matrix& other);

            /**
             * Operator to get a reference to the row at the specified index
             * @param i The index of the row to return
             * @return A reference to the row at the specified index
             * @throws std::invalid_argument if the index does not exist
             */
            MatrixRow& operator[](int i);

            /**
             * Operator to get a const reference to the row at the specified index
             * @param i The index of the row to return
             * @return A const reference to the element at the specified index
             * @throws std::invalid_argument if the index does not exist
             */
            const MatrixRow& operator[](int i) const;

            /**
             * Gets a specified column vector of the matrix
             * @param i The index of the column vector to return
             * @return The column vector at the specified index
             * @throws std::invalid_argument if the index does not exist
             */
            Vector getCol(int i);

            /**
             * Gets a specified row vector of the matrix
             */
            Vector getRow(int i);

            /**
             * Gets the number of rows of the matrix
             * @return number of rows of the matrix
             */
            int rows() const;

            /**
             * Gets the number of columns of the matrix
             * @return number of columns of the matrix
             */
            int cols() const;

            /**
             * Returns the transpose of the matrix
             */
            Matrix transpose();

            /**
             * Calculates the frobenius norm of the matrix
             */
            double norm();

            /**
             * Computes the row echelon form of the matrix using Gauss-Jordan elimination
             */
            Matrix ref();

            /**
             * Computes the reduced row echelon form of the matrix using Gauss-Jordan elimination
             */
            Matrix rref();

            /**
             * Calculates the determinant of the matrix using the Laplace expansion
             * @throws std::invalid_argument if the matrix is not square
             */
            double det();

            /**
             * Computes the i,j minor of the matrix
             */
            Matrix minor(int i, int j);

            /**
             * Computes the i,j cofactor of the matrix
             */
            double cofactor(int i, int j);

            /**
             * Computes the matrix inverse using the adjoint matrix
             */
            Matrix inverse();

            /**
             * Returns a string representation of the matrix
             */
            std::string toString();

        };

        /**
         * Operator for the sum of two matrices
         * @throws std::invalid_argument if matrix dimensions do not match
         */
        Matrix operator+(const Matrix& a, const Matrix& b);

        /**
         * Operator for the difference of two matrices
         * @throws std::invalid_argument if matrix dimensions do not match
         */
        Matrix operator-(const Matrix& a, const Matrix& b);

        /**
         * Operator for the product of two matrices
         * @throws std::invalid_argument if matrix dimensions can't be multiplied
         */
        Matrix operator*(const Matrix& a, const Matrix& b);

        /**
         * Operator for scalar multiplication with matrix first
         * @return The result of the scalar multiplication
         */
        Matrix operator*(const Matrix& a, const double& b);

        /**
         * Operator for scaler multiplication with scalar first
         * @return The result of the scalar multiplication
         */
        Matrix operator*(const double& a, const Matrix& b);

        /**
         * Operator for matrix-vector multiplication
         * @throws std::invalid_argument if matrix and vector dimensions can't be multiplied
         */
        Vector operator*(const Matrix& a, const Vector& b);

    } // LouLib
} // Math

#endif //LOULIB_MATRIX_HPP
