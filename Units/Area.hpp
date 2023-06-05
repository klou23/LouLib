/**
 * @file Area.hpp
 *
 * Definition of Area units
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


#ifndef LOULIB_AREA_HPP
#define LOULIB_AREA_HPP

#include "BaseUnit.hpp"
#include "UnitMath.hpp"
#include "Length.hpp"

namespace LouLib{
    namespace Units{
        DEFINE_NEW_UNIT(2, 0, 0, 0, 0, 0, 0, 0, Area);

        constexpr Area SQUARE_METER = METER * METER;
        constexpr Area SQUARE_DECIMETER = DECIMETER * DECIMETER;
        constexpr Area SQUARE_CENTIMETER = CENTIMETER * CENTIMETER;
        constexpr Area SQUARE_MILLIMETER = MILLIMETER * MILLIMETER;
        constexpr Area SQUARE_INCH = INCH * INCH;
        constexpr Area SQUARE_FOOT = FOOT * FOOT;
        constexpr Area SQUARE_YARD = YARD * YARD;
        constexpr Area SQUARE_TILE = TILE * TILE;

        inline namespace literals{
            #define CREATE_AREA_STRING_LITERAL(literal, unit)             \
            constexpr Area operator"" literal(long double x){             \
                return static_cast<double>(x)*unit;                         \
            }                                                               \
            constexpr Area operator"" literal(unsigned long long int x){  \
                return static_cast<double>(x)*unit;                         \
            }

            CREATE_AREA_STRING_LITERAL(_m2, SQUARE_METER);
            CREATE_AREA_STRING_LITERAL(_dm2, SQUARE_DECIMETER);
            CREATE_AREA_STRING_LITERAL(_cm2, SQUARE_CENTIMETER);
            CREATE_AREA_STRING_LITERAL(_mm2, SQUARE_MILLIMETER);
            CREATE_AREA_STRING_LITERAL(_in2, SQUARE_INCH);
            CREATE_AREA_STRING_LITERAL(_ft2, SQUARE_FOOT);
            CREATE_AREA_STRING_LITERAL(_yd2, SQUARE_YARD);
            CREATE_AREA_STRING_LITERAL(_tl2, SQUARE_TILE);
        }
    }
}

#endif //LOULIB_AREA_HPP
