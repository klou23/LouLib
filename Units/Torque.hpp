/**
 * Torque.hpp
 *
 * Definition of Torque units
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

#ifndef LOULIB_TORQUE_HPP
#define LOULIB_TORQUE_HPP

#include "BaseUnit.hpp"
#include "UnitMath.hpp"
#include "Mass.hpp"
#include "Length.hpp"
#include "Time.hpp"
#include "Force.hpp"

namespace LouLib{
    namespace Units{
        DEFINE_NEW_UNIT(2, 1, -2, 0, 0, 0, 0, 0, Torque);

        constexpr Torque NEWTON_METER = NEWTON * METER;

        inline namespace literals{
            #define CREATE_TORQUE_STRING_LITERAL(literal, unit)             \
            constexpr Torque operator"" literal(long double x){             \
                return static_cast<double>(x)*unit;                         \
            }                                                               \
            constexpr Torque operator"" literal(unsigned long long int x){  \
                return static_cast<double>(x)*unit;                         \
            }

            CREATE_TORQUE_STRING_LITERAL(_Nm, NEWTON_METER);
        }
    }
}

#endif //LOULIB_TORQUE_HPP
