/**
 * LQRController.hpp
 *
 * Header file for the LQRController class
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

#ifndef LOULIB_LQRCONTROLLER_HPP
#define LOULIB_LQRCONTROLLER_HPP

#include "../Math/Math.hpp"

namespace LouLib {
    namespace Controllers {

        class LQRController {
        private:
            Math::Matrix A;
            Math::Matrix B;
            Math::Matrix Q;
            Math::Matrix R;

            Math::Matrix P{0,0};
            Math::Matrix K{0,0};

            Math::Vector reference{0};
            Math::Vector actual{0};

            void solveDARE();

        public:
            LQRController(const Math::Matrix &a, const Math::Matrix &b,
                          const Math::Matrix &q, const Math::Matrix &r);

            Math::Matrix getK();

            Math::Vector computeControl(Math::Vector x);

            void setReference(const Math::Vector &_reference);
        };

    } // LouLib
} // Controllers

#endif //LOULIB_LQRCONTROLLER_HPP
