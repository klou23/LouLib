#ifndef LOULIB_MATRIX_HPP
#define LOULIB_MATRIX_HPP

#include <vector>
#include "Vector.hpp"
#include <stdexcept>
#include "MathConstants.hpp"
#include "MathFunctions.hpp"

namespace LouLib {
    namespace Math {

        class Matrix {
        private:
            class MatrixRow{
            private:
                std::vector<double> data;

            public:
                /**
                 * Constructs a new matrix row of the given size
                 */
                MatrixRow(int n);

                /**
                 * Constructs a new matrix row with the given data
                 */
                MatrixRow(std::initializer_list<double> rowData);

                /**
                 * Constructs a new matrix row with the given data
                 */
                MatrixRow(std::vector<double> rowData);

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
        };

    } // LouLib
} // Math

#endif //LOULIB_MATRIX_HPP
