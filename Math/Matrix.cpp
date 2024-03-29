/**
 * @file Matrix.cpp
 *
 * Implementation file for the Matrix class
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

#include "Matrix.hpp"
#include "MathConstants.hpp"

namespace LouLib {
    namespace Math {
        Matrix::MatrixRow::MatrixRow(int n) {
            data.resize(n, 0);
        }

        Matrix::MatrixRow::MatrixRow(std::initializer_list<double> rowData) : data(rowData) {}

        Matrix::MatrixRow::MatrixRow(std::vector<double> rowData) : data(std::move(rowData)) {}

        Matrix::MatrixRow::MatrixRow(const Matrix::MatrixRow &other) : data(other.data) {}

        double &Matrix::MatrixRow::operator[](int i) {
            if(i < 0 || i >= data.size()){
                throw std::invalid_argument("Index out of bounds");
            }
            return data[i];
        }

        const double &Matrix::MatrixRow::operator[](int i) const {
            if(i < 0 || i >= data.size()){
                throw std::invalid_argument("Index out of bounds");
            }
            return data[i];
        }

        int Matrix::MatrixRow::size() const {
            return (int) data.size();
        }

        Vector Matrix::MatrixRow::getVector() {
            return Vector(data);
        }

        Matrix::Matrix(int rows, int cols) {
            data.resize(rows, MatrixRow(cols));
        }

        Matrix::Matrix(std::initializer_list<std::initializer_list<double>> matrixData) {
            data.resize(0, MatrixRow(0));
            for(auto it = matrixData.begin(); it != matrixData.end(); it++){
                data.emplace_back(*it);
            }
        }

        Matrix::Matrix(std::vector<std::vector<double>> matrixData) {
            data.resize(0, MatrixRow(0));
            for(auto it = matrixData.begin(); it != matrixData.end(); it++){
                data.emplace_back(*it);
            }
        }

        Matrix::Matrix(std::vector<MatrixRow> matrixData) {
            data = std::move(matrixData);
        }

        Matrix::Matrix(const Matrix &other) : data(other.data) {}

        Matrix::MatrixRow &Matrix::operator[](int i) {
            if(i < 0 || i >= data.size()){
                throw std::invalid_argument("Index out of bounds");
            }
            return data[i];
        }

        const Matrix::MatrixRow &Matrix::operator[](int i) const {
            if(i < 0 || i >= data.size()){
                throw std::invalid_argument("Index out of bounds");
            }
            return data[i];
        }

        Vector Matrix::getCol(int i) {
            if(i < 0 || i >= cols()){
                throw std::invalid_argument("Index out of bounds");
            }
            Vector sol(rows());
            for(int j = 0; j < rows(); j++){
                sol[j] = data[j][i];
            }
            return sol;
        }

        Vector Matrix::getRow(int i) {
            if(i < 0 || i >= data.size()){
                throw std::invalid_argument("Index out of bounds");
            }
            return data[i].getVector();
        }

        int Matrix::rows() const {
            return (int) data.size();
        }

        int Matrix::cols() const {
            return (int) data[0].size();
        }

        Matrix Matrix::transpose() {
            Matrix sol(cols(), rows());
            for(int i = 0; i < rows(); i++){
                for(int j = 0; j < cols(); j++){
                    sol[j][i] = data[i][j];
                }
            }
            return sol;
        }

        double Matrix::norm() {
            double sol = 0;
            for(int i = 0; i < rows(); i++){
                for(int j = 0; j < cols(); j++){
                    sol += data[i][j] * data[i][j];
                }
            }
            return std::sqrt(sol);
        }

        double Matrix::det() {
            if(rows() != cols()){
                throw std::invalid_argument("Cannot calculate determinant of a non-square matrix");
            }
            Matrix a(data);
            int n = a.rows();
            double det = 1;
            for(int i = 0; i < n; i++) {
                int k = i;
                for (int j = i+1; j < n; j++) {
                    if (std::abs(a[j][i]) > std::abs(a[k][i])){
                        k = j;
                    }
                }
                if (std::abs(a[k][i]) < Math::EPS) {
                    det = 0;
                    break;
                }
                std::swap(a[i], a[k]);
                if (i != k){
                    det = -det;
                }
                det *= a[i][i];
                for (int j = i+1; j < n; j++){
                    a[i][j] /= a[i][i];
                }
                for (int j = 0; j < n; j++){
                    if (j != i && std::abs(a[j][i]) > Math::EPS){
                        for (k=i+1; k<n; ++k){
                            a[j][k] -= a[i][k] * a[j][i];
                        }
                    }
                }
            }
            return det;
        }

        Matrix Matrix::minor(int i, int j){
            Matrix sol(rows()-1, cols()-1);
            for(int r = 0; r < rows(); r++){
                if(r == i) continue;
                int newR = (r < i) ? r : r-1;
                for(int c = 0; c < cols(); c++){
                    if(c == j) continue;
                    int newC = (c < j) ? c : c-1;
                    sol[newR][newC] = data[r][c];
                }
            }
            return sol;
        }

        double Matrix::cofactor(int i, int j) {
            return std::pow(-1, i+j) * minor(i, j).det();
        }

        Matrix Matrix::inverse() {
            if(rows() != cols() || det() < Math::EPS){
                throw std::logic_error("Matrix not invertible");
            }
            int n = rows();
            Matrix identity(n, n);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    identity[i][j] = i==j ? 1 : 0;
                }
            }
            Matrix augmented = getAugmented(identity);
            Matrix reducedAug = augmented.rref();
            Matrix sol(n, n);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    sol[i][j] = reducedAug[i][j+n];
                }
            }
            return reducedAug;
        }

        std::string Matrix::toString() {
            std::string sol = "{";
            for(int i = 0; i < rows(); i++){
                sol += data[i].getVector().toString();
                if(i != rows()-1) sol += ",\n";
            }
            sol += "}";
            return sol;
        }

        Matrix Matrix::ref() {
            Matrix sol(data);
            int row = 0;
            for(int col = 0; col < cols(); col++){
                //find pivot using partial pivoting
                double maxVal = Math::EPS;
                int k = -1;
                for(int i = row; i < rows(); i++){
                    if(std::abs(sol[i][col]) > maxVal){
                        k = i;
                        maxVal = std::abs(sol[i][col]);
                    }
                }
                if(k == -1){
                    continue;   //column is already reduced
                }
                //swap rows
                std::swap(sol[row], sol[k]);

                //make pivot 1
                for(int j = 0; j < cols(); j++){
                    sol[row][j] /= sol[row][col];
                }

                //clear column below
                for(int i = row+1; i < rows(); i++){
                    double mult = sol[i][col] / sol[row][col];
                    for(int j = 0; j < cols(); j++){
                        sol[i][j] -= mult * sol[row][j];
                    }
                }

                row++;
                if(row == rows()) break;
            }
            return sol;
        }

        Matrix Matrix::rref() {
            Matrix sol = ref();
            for(int row = rows()-1; row >= 0; row--){
                //find pivot column
                int col = 0;
                while(col < cols() && sol[row][col] < Math::EPS){
                    col++;
                }
                if(col == cols()){
                    continue;   //row is empty
                }
                //create zeroes above the pivot
                for(int i = row-1; i >= 0; i--){
                    double mult = sol[i][col];
                    for(int j = 0; j < cols(); j++){
                        sol[i][j] -= mult * sol[row][j];
                    }
                }
            }
            return sol;
        }

        int Matrix::rank() {
            Matrix A(data);
            int n = A.rows();
            int m = A.cols();

            int rank = 0;
            std::vector<bool> row_selected(n, false);
            for(int i = 0; i < m; i++) {
                int j;
                for(j = 0; j < n; ++j) {
                    if(!row_selected[j] && std::abs(A[j][i]) > Math::EPS) break;
                }

                if(j != n) {
                    rank++;
                    row_selected[j] = true;
                    for(int p = i + 1; p < m; p++) A[j][p] /= A[j][i];
                    for(int k = 0; k < n; k++) {
                        if (k != j && std::abs(A[k][i]) > Math::EPS) {
                            for(int p = i + 1; p < m; p++){
                                A[k][p] -= A[j][p] * A[k][i];
                            }
                        }
                    }
                }
            }
            return rank;
        }

        Matrix Matrix::getAugmented(const Matrix &o) {
            if(rows() != o.rows()){
                throw std::invalid_argument("Matrix rows don't match");
            }
            int n = rows();
            int m1 = cols();
            int m2 = o.cols();
            Matrix sol(n, m1+m2);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m1+m2; j++){
                    if(j < m1) sol[i][j] = data[i][j];
                    else sol[i][j] = o[i][j-m1];
                }
            }
            return sol;
        }

        Matrix operator+(const Matrix &a, const Matrix &b) {
            if(a.rows() != b.rows() || a.cols() != b.cols()){
                throw std::invalid_argument("Matrix dimensions don't match");
            }
            Matrix sol(a.rows(), a.cols());
            for(int i = 0; i < a.rows(); i++){
                for(int j = 0; j < a.cols(); j++){
                    sol[i][j] = a[i][j] + b[i][j];
                }
            }
            return sol;
        }

        Matrix operator-(const Matrix &a, const Matrix &b) {
            if(a.rows() != b.rows() || a.cols() != b.cols()){
                throw std::invalid_argument("Matrix dimensions don't match");
            }
            Matrix sol(a.rows(), a.cols());
            for(int i = 0; i < a.rows(); i++){
                for(int j = 0; j < a.cols(); j++){
                    sol[i][j] = a[i][j] - b[i][j];
                }
            }
            return sol;
        }

        Matrix operator*(const Matrix &a, const Matrix &b) {
            if(a.cols() != b.rows()){
                throw std::invalid_argument("Matrix dimensions can't be multiplied");
            }

            Matrix sol(a.rows(), b.cols());

            for(int i = 0; i < a.rows(); i++){
                for(int j = 0; j < b.cols(); j++){
                    double sum = 0;
                    for(int k = 0; k < a.cols(); k++){
                        sum += a[i][k] * b[k][j];
                    }
                    sol[i][j] = sum;
                }
            }

            return sol;
        }

        Matrix operator*(const Matrix &a, const double &b) {
            Matrix sol(a.rows(), a.cols());
            for(int i = 0; i < a.rows(); i++){
                for(int j = 0; j < a.cols(); i++){
                    sol[i][j] = b * a[i][j];
                }
            }
            return sol;
        }

        Matrix operator*(const double &a, const Matrix &b) {
            Matrix sol(b.rows(), b.cols());
            for(int i = 0; i < b.rows(); i++){
                for(int j = 0; j < b.cols(); j++){
                    sol[i][j] = a * b[i][j];
                }
            }
            return sol;
        }

        Vector operator*(const Matrix &a, const Vector &b) {
            if(a.cols() != b.size()){
                throw std::invalid_argument("Matrix and vector dimensions can't be multiplied");
            }

            Vector sol(a.rows());
            for(int i = 0; i < a.rows(); i++){
                double sum = 0;
                for(int j = 0; j < a.cols(); j++){
                    sum += a[i][j] * b[j];
                }
                sol[i] = sum;
            }

            return sol;
        }


    } // LouLib
} // Math