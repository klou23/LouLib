/**
 * @file MathFunctions.hpp
 *
 * Contains commonly used math functions
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

#ifndef LOULIB_MATHFUNCTIONS_HPP
#define LOULIB_MATHFUNCTIONS_HPP

namespace LouLib{
    namespace Math{
        /**
         * Returns the sign of a number
         */
         int signum(double a);

         /**
          * Returns the value clamped between the max and min
          */
          double clamp(double val, double min, double max);

          /**
           * Ensures angle is in the range of [-180, 180)
           * @param x
           * @return
           */
          double constrainAngle(double x);

          /**
           * Returns the difference of the final and initial angles
           * Must be in degrees
           */
           double angleDifference(double final, double initial);

           /**
            * Computes a power of integers using binary exponentiation
            * @return a^b
            * @warning If there is a risk of integer overflow, it is better to
            * use the long long version of this function
            */
            int binpow(int a, int b);

            /**
             * Computes a power of integers using binary exponentiation
             * @return a^b
             */
             long long binpow(long long a, long long b);
    }
}

#endif //LOULIB_MATHFUNCTIONS_HPP
