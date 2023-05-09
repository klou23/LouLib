/**
 * Time.hpp
 *
 * Definition of Time units
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

#ifndef LOULIB_TIME_HPP
#define LOULIB_TIME_HPP

#include "BaseUnit.hpp"
#include "UnitMath.hpp"

namespace LouLib{
    namespace Units{
        DEFINE_NEW_UNIT(0, 0, 1, 0, 0, 0, 0, 0, Time);

        //base unit
        constexpr Time SECOND(1.0);

        //metrix units
        constexpr Time DECISECOND = SECOND * 0.1;
        constexpr Time CENTISECOND = SECOND * 0.01;
        constexpr Time MILLISECOND = SECOND * 0.001;

        //other units
        constexpr Time MINUTE = SECOND * 60;
        constexpr Time HOUR = MINUTE * 60;

        inline namespace literals{
            #define CREATE_TIME_STRING_LITERAL(literal, unit)             \
            constexpr Time operator"" literal(long double x){             \
                return static_cast<double>(x)*unit;                         \
            }                                                               \
            constexpr Time operator"" literal(unsigned long long int x){  \
                return static_cast<double>(x)*unit;                         \
            }

            CREATE_TIME_STRING_LITERAL(_s, SECOND);
            CREATE_TIME_STRING_LITERAL(_ds, DECISECOND);
            CREATE_TIME_STRING_LITERAL(_cs, CENTISECOND);
            CREATE_TIME_STRING_LITERAL(_ms, MILLISECOND);
            CREATE_TIME_STRING_LITERAL(_min, MINUTE);
            CREATE_TIME_STRING_LITERAL(_hr, HOUR);
        }
    }
}

#endif //LOULIB_TIME_HPP
