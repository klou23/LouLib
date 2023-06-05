/**
 * @file Length.hpp
 *
 * Definition of Length units
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

#ifndef LOULIB_LENGTH_HPP
#define LOULIB_LENGTH_HPP

#include "BaseUnit.hpp"
#include "UnitMath.hpp"

namespace LouLib{
    namespace Units{
        DEFINE_NEW_UNIT(1, 0, 0, 0, 0, 0, 0, 0, Length);

        //base unit
        constexpr Length METER(1.0);

        //metric units
        constexpr Length DECIMETER = METER * 0.1;
        constexpr Length CENTIMETER = METER * 0.01;
        constexpr Length MILLIMETER = METER * 0.001;

        //imperial units
        constexpr Length INCH = METER * 0.0254;
        constexpr Length FOOT = INCH * 12.0;
        constexpr Length YARD = FOOT * 3;

        //VEX Units
        constexpr Length TILE = FOOT * 2;

        inline namespace literals{
            #define CREATE_LENGTH_STRING_LITERAL(literal, unit)             \
            constexpr Length operator"" literal(long double x){             \
                return static_cast<double>(x)*unit;                         \
            }                                                               \
            constexpr Length operator"" literal(unsigned long long int x){  \
                return static_cast<double>(x)*unit;                         \
            }

            CREATE_LENGTH_STRING_LITERAL(_m, METER);
            CREATE_LENGTH_STRING_LITERAL(_dm, DECIMETER);
            CREATE_LENGTH_STRING_LITERAL(_cm, CENTIMETER);
            CREATE_LENGTH_STRING_LITERAL(_mm, MILLIMETER);
            CREATE_LENGTH_STRING_LITERAL(_in, INCH);
            CREATE_LENGTH_STRING_LITERAL(_ft, FOOT);
            CREATE_LENGTH_STRING_LITERAL(_yd, YARD);
            CREATE_LENGTH_STRING_LITERAL(_tl, TILE);
        }
    }
}

#endif //LOULIB_LENGTH_HPP
