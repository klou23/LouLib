/**
 * @file MathFunctions.cpp
 *
 * Contains implementations of commonly used math functions
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

#include "MathFunctions.hpp"

#include <cmath>

namespace LouLib{
    namespace Math{

        int signum(double a){
            if(a == 0) return 0;
            return a > 0 ? 1 : -1;
        }

        double clamp(double val, double min, double max) {
            if(val < min) return min;
            else if(val > max) return max;
            return val;
        }

        double constrainAngle(double x) {
            double sol = std::fmod(x + 180.0, 360.0);
            if(sol < 0) sol += 360;
            return sol - 180;
        }

        double angleDifference(double final, double initial) {
            double diff = final - initial;
            return constrainAngle(diff);
        }

        int binpow(int a, int b){
            int sol = 1;
            while(b > 0){
                if(b&1) sol *= a;
                b >>= 1;
                a *= a;
            }
            return sol;
        }

        long long binpow(long long a, long long b){
            long long sol = 1;
            while(b > 0){
                if(b&1) sol *= a;
                b >>= 1;
                a *= a;
            }
            return sol;
        }

    }
}