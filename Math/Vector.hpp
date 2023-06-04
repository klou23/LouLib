/**
 * Vector.hpp
 *
 * Header file for the Vector class
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

#ifndef LOULIB_VECTOR_HPP
#define LOULIB_VECTOR_HPP

#include <vector>
#include <stdexcept>
#include <cmath>

namespace LouLib {
    namespace Math {

        /**
         * @class Vector
         * @brief A class representing a mathematical vector
         */
        class Vector {
        private:
            std::vector<double> data;

        public:
            /**
             * Constructs a new vector of the given size.
             */
            explicit Vector(int n);

            /**
             * Constructs a new vector with the given data.
             */
            Vector(std::initializer_list<double> vectorData);

            /**
             * Constructs a new vector with the given data
             */
            explicit Vector(std::vector<double> vectorData);

            /**
             * Constructs a new vector that is a copy of the given vector
             */
            Vector(const Vector& other);

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
             * Returns the size of the vector
             */
            int size() const;

            /**
             * Calculates the norm/magnitude of the vector
             */
            double norm();

            /**
             * Calculates a new vector with the same direction as this vector,
             * but a magnitude of 1
             */
            Vector normalize();

            /**
             * Returns a string representation of the vector
             */
            std::string toString();
        };

        /**
         * Operator for the sum of two vectors
         * @throws std::invalid_argument if the vectors have different sizes
         */
        Vector operator+(const Vector& a, const Vector& b);

        /**
         * Operator for the difference of two vectors
         * @throws std::invalid_argument if the vectors have different sizes
         */
        Vector operator-(const Vector& a, const Vector& b);

        /**
         * Operator for dot product of two vectors
         * @throws std::invalid_argument if the vectors have different sizes
         */
        double operator*(const Vector& a, const Vector& b);

        /**
         * Operator for scalar multiplication with scalar first
         */
        Vector operator*(const double& a, const Vector& b);

        /**
         * Operator for scalar multiplication with vector first
         */
        Vector operator*(const Vector& a, const double& b);

    } // Math
} // LouLib

#endif //LOULIB_VECTOR_HPP
