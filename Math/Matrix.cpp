#include "Matrix.hpp"

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
            if(i <= 0 || i >= cols()){
                throw std::invalid_argument("Index out of bounds");
            }
            Vector sol(rows());
            for(int j = 0; j < rows(); j++){
                sol[j] = data[j][i];
            }
            return sol;
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

        
    } // LouLib
} // Math