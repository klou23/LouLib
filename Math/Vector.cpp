/**
 * Vector.cpp
 *
 * Implementation file for the Vector class
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

#include "Vector.hpp"
#include <utility>

namespace LouLib {
    namespace Math {

        Vector::Vector(int n){
            data.resize(n, 0);
        }

        Vector::Vector(std::initializer_list<double> vectorData) : data(vectorData) {}

        Vector::Vector(std::vector<double> vectorData) : data(std::move(vectorData)) {}

        Vector::Vector(const Vector& other) : data(other.data) {}

        double& Vector::operator[](int i) {
            if(i < 0 || i >= data.size()){
                throw std::invalid_argument("Index out of bounds");
            }
            return data[i];
        }

        const double& Vector::operator[](int i) const {
            if(i < 0 || i >= data.size()){
                throw std::invalid_argument("Index out of bounds");
            }
            return data[i];
        }

        int Vector::size() const {
            return (int) data.size();
        }

        double Vector::norm() {
            double sol = 0;
            for(int i = 0; i < size(); i++){
                sol += data[i] * data[i];
            }
            return std::sqrt(sol);
        }

        Vector Vector::normalize() {
            Vector result(size());
            double mag = norm();
            for(int i = 0; i < size(); i++){
                result[i] = data[i] / mag;
            }
            return result;
        }

        std::string Vector::toString() {
            std::string sol = "{";
            for(int i = 0; i < data.size(); i++){
                sol += std::to_string(data[i]);
                if(i != data.size()-1) sol += ", ";
            }
            sol += "}";
            return sol;
        }

        Vector operator+(const Vector &a, const Vector &b) {
            if(a.size() != b.size()){
                throw std::invalid_argument("Vectors must have the same size.");
            }
            Vector result(a.size());
            for (int i = 0; i < a.size(); i++) {
                result[i] = a[i] + b[i];
            }
            return result;
        }

        Vector operator-(const Vector &a, const Vector &b) {
            if(a.size() != b.size()){
                throw std::invalid_argument("Vectors must have the same size.");
            }
            Vector result(a.size());
            for (int i = 0; i < a.size(); i++) {
                result[i] = a[i] - b[i];
            }
            return result;
        }

        double operator*(const Vector &a, const Vector &b) {
            if(a.size() != b.size()){
                throw std::invalid_argument("Vectors must have the same size.");
            }
            double result = 0;
            for(int i = 0; i < a.size(); i++){
                result += a[i] * b[i];
            }
            return result;
        }

        Vector operator*(const double &a, const Vector &b) {
            Vector result(b.size());
            for(int i = 0; i < b.size(); i++){
                result[i] = b[i] * a;
            }
            return result;
        }

        Vector operator*(const Vector &a, const double &b) {
            Vector result(a.size());
            for(int i = 0; i < a.size(); i++){
                result[i] = a[i] * b;
            }
            return result;
        }

    } // Math
} // LouLib