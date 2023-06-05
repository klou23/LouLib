/**
 * @file Mass.hpp
 *
 * Definition of Mass units
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

#ifndef LOULIB_MASS_HPP
#define LOULIB_MASS_HPP

#include "BaseUnit.hpp"
#include "UnitMath.hpp"

namespace LouLib{
    namespace Units{
        DEFINE_NEW_UNIT(0, 1, 0 , 0, 0, 0, 0, 0, Mass);

        //base unit
        constexpr Mass KILOGRAM(1.0);

        //metric units
        constexpr Mass HECTOGRAM = KILOGRAM * 0.1;
        constexpr Mass DECAGRAM = KILOGRAM * 0.01;
        constexpr Mass GRAM = KILOGRAM * 0.001;

        //imperial units
        constexpr Mass OUNCE = KILOGRAM * 0.02834952;
        constexpr Mass POUND = OUNCE * 16.0;

        inline namespace literals{
            #define CREATE_MASS_STRING_LITERAL(literal, unit)               \
            constexpr Mass operator"" literal(long double x){               \
                return static_cast<double>(x) * unit;                       \
            }                                                               \
            constexpr Mass operator"" literal(unsigned long long int x){    \
                return static_cast<double>(x) * unit;                       \
            }

            CREATE_MASS_STRING_LITERAL(_kg, KILOGRAM);
            CREATE_MASS_STRING_LITERAL(_hg, HECTOGRAM);
            CREATE_MASS_STRING_LITERAL(_dag, DECAGRAM);
            CREATE_MASS_STRING_LITERAL(_g, GRAM);
            CREATE_MASS_STRING_LITERAL(_oz, OUNCE);
            CREATE_MASS_STRING_LITERAL(_lb, POUND);
        }
    }
}

#endif //LOULIB_MASS_HPP
