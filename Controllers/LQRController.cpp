/**
 * @file LQRController.cpp
 *
 * Implementation file for the LQRController class
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

#include "LQRController.hpp"

namespace LouLib {
    namespace Controllers {
        LQRController::LQRController(const Math::Matrix &a, const Math::Matrix &b,
                const Math::Matrix &q, const Math::Matrix &r) : A(a), B(b), Q(q), R(r) {}

        void LQRController::setReference(const Math::Vector &_reference) {
            reference = _reference;
        }

        void LQRController::solveDARE() {
            double tolerance = 1E-5;
            double iter_max = 1000;

            P = Q;

            Math::Matrix P_next(0,0);

            Math::Matrix At = A.transpose();
            Math::Matrix Bt = B.transpose();
            Math::Matrix Rinv = R.inverse();

            double diff;

            for(int i = 0; i < iter_max; i++){
                P_next = At * P * A -
                         At * P * B * (R + Bt * P * B).inverse() * Bt * P * A + Q;

                diff = fabs((P_next - P).norm());
                P = P_next;

                if(diff < tolerance) break;
            }

            K = (R + Bt * P * B).inverse() * (Bt * P * A);
        }

        Math::Matrix LQRController::getK() {
            return K;
        }

        Math::Vector LQRController::computeControl(Math::Vector x) {
            return -1*K * (reference - x);
        }


    } // LouLib
} // Controllers