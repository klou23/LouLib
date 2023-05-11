/**
 * PiecewisePolynomial.hpp
 *
 * Header file for the PiecewisePolynomial class
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

#ifndef LOULIB_PIECEWISEPOLYNOMIAL_HPP
#define LOULIB_PIECEWISEPOLYNOMIAL_HPP

#include <vector>
#include "PiecewisePolynomialPart.hpp"
#include <stdexcept>

namespace LouLib{
    namespace Math{
        class PiecewisePolynomial {
        private:

            std::vector<PiecewisePolynomialPart> pieces;

            /**
             * Inserts
             * @param p
             */
            void insert(PiecewisePolynomialPart p);

        public:

            PiecewisePolynomial();

            explicit PiecewisePolynomial(std::vector<PiecewisePolynomialPart> p);

            /**
             * Returns the piecewise polynomial part that corresponds to the given x-value.
             * @throw std::invalid_argument if there is no part corresponding to the given x-value.
             */
            PiecewisePolynomialPart getPart(double x);

            double evaluate(double x);
        };
    }
}


#endif //LOULIB_PIECEWISEPOLYNOMIAL_HPP
