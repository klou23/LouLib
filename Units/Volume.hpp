/**
 * Volume.hpp
 *
 * Definition of Volume units
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

#ifndef LOULIB_VOLUME_HPP
#define LOULIB_VOLUME_HPP

#include "BaseUnit.hpp"
#include "UnitMath.hpp"
#include "Length.hpp"

namespace LouLib {
    namespace Units {
        DEFINE_NEW_UNIT(3, 0, 0, 0, 0, 0, 0, 0, Volume);

        constexpr Volume CUBIC_METER = METER * METER * METER;
        constexpr Volume CUBIC_DECIMETER = DECIMETER * DECIMETER * DECIMETER;
        constexpr Volume CUBIC_CENTIMETER = CENTIMETER * CENTIMETER * CENTIMETER;
        constexpr Volume CUBIC_MILLIMETER = MILLIMETER * MILLIMETER * MILLIMETER;
        constexpr Volume CUBIC_INCH = INCH * INCH * INCH;
        constexpr Volume CUBIC_FOOT = FOOT * FOOT * FOOT;
        constexpr Volume CUBIC_YARD = YARD * YARD * YARD;
        constexpr Volume CUBIC_TILE = TILE * TILE * TILE;

        inline namespace literals{
            #define CREATE_VOLUME_STRING_LITERAL(literal, unit)             \
            constexpr Volume operator"" literal(long double x){             \
                return static_cast<double>(x)*unit;                         \
            }                                                               \
            constexpr Volume operator"" literal(unsigned long long int x){  \
                return static_cast<double>(x)*unit;                         \
            }

            CREATE_VOLUME_STRING_LITERAL(_m3, CUBIC_METER);
            CREATE_VOLUME_STRING_LITERAL(_dm3, CUBIC_DECIMETER);
            CREATE_VOLUME_STRING_LITERAL(_cm3, CUBIC_CENTIMETER);
            CREATE_VOLUME_STRING_LITERAL(_mm3, CUBIC_MILLIMETER);
            CREATE_VOLUME_STRING_LITERAL(_in3, CUBIC_INCH);
            CREATE_VOLUME_STRING_LITERAL(_ft3, CUBIC_FOOT);
            CREATE_VOLUME_STRING_LITERAL(_yd3, CUBIC_YARD);
            CREATE_VOLUME_STRING_LITERAL(_tl3, CUBIC_TILE);
        }
    }
}

#endif //LOULIB_VOLUME_HPP
