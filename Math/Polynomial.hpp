/**
 * Polynomial.hpp
 *
 * Header file for the polynomial class
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

#ifndef LOULIB_POLYNOMIAL_HPP
#define LOULIB_POLYNOMIAL_HPP

#include <vector>
#include <cmath>

namespace LouLib {
    namespace Math {

        class Polynomial {
        private:
            std::vector<double> coefficients;

        public:

            /**
             * Constructs a new polynomial with the given degree
             * @param degree polynomial degree
             */
            Polynomial(int degree);

            /**
             * Constructs a new polynomial with the given coefficients
             * @param coefficients coefficients
             */
            Polynomial(std::initializer_list<double> coefficients);

            /**
             * Constructs a new polynomial with the given coefficients
             * @param coefficients coefficients
             */
            Polynomial(std::vector<double> coefficients);

            /**
             * Gets the coefficient of the i-th degree term
             * @param i degree
             * @return the coefficient of the i-th degree term
             */
            double getCoefficient(int i);

            /**
             * Evaluates the polynomial at the given x-value
             * @param x x-value
             * @return the value of the polynomial at the given x-value
             */
            double evaluate(double x);
        };

    } // LouLib
} // Math

#endif //LOULIB_POLYNOMIAL_HPP
