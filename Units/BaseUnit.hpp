/**
 * BaseUnit.hpp
 *
 * Contains the BaseUnit class.
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

#ifndef LOULIB_BASEUNIT_HPP
#define LOULIB_BASEUNIT_HPP

#include <ratio>
#include <stdexcept>

namespace LouLib {
    namespace Units {

        template<typename lengthDim, typename massDim, typename timeDim, typename currentDim,
                 typename temperatureDim, typename substanceDim, typename luminosityDim,
                 typename angleDim>
        class BaseUnit {
        private:
            double value;

            /**
             * Checks if another BaseUnit has the same dimensions
             */
            template <typename L, typename M, typename t, typename Q,
                    typename T, typename N, typename J, typename A>
            constexpr bool sameDim(const BaseUnit<L, M, t, Q, T, N, J, A>& a) const{
                if(!std::ratio_equal<lengthDim, L>::value) return false;
                if(!std::ratio_equal<massDim, M>::value) return false;
                if(!std::ratio_equal<timeDim, t>::value) return false;
                if(!std::ratio_equal<currentDim, Q>::value) return false;
                if(!std::ratio_equal<temperatureDim, T>::value) return false;
                if(!std::ratio_equal<substanceDim, N>::value) return false;
                if(!std::ratio_equal<luminosityDim, J>::value) return false;
                if(!std::ratio_equal<angleDim, A>::value) return false;
                return true;
            }

        public:
            /**
             * Constructor
             */
            constexpr explicit BaseUnit(double val) : value(val){}

            /**
             * Addition Assignment Operator
             */
            constexpr BaseUnit const& operator+=(const BaseUnit& a){
                if(!sameDim(a)){
                    throw std::invalid_argument("Dimensions do not match");
                }
                value += a.val();
                return *this;
            }

            /**
             * Subtraction Assignment Operator
             */
            constexpr BaseUnit const& operator-=(const BaseUnit& a){
                if(!sameDim(a)){
                    throw std::invalid_argument("Dimensions do not match");
                }
                value -= a.val();
                return *this;
            }

            /**
             * Scalar Multiplication Assignment Operator
             */
             constexpr BaseUnit const& operator*=(const double& a){
                 value *= a;
                 return *this;
             }

            /**
             * Scalar Division Assignment Operator
             */
            constexpr BaseUnit const& operator/=(const double& a){
                value /= a;
                return *this;
            }

            /**
             * Negation Operator
             */
             constexpr BaseUnit operator-(){
                 return BaseUnit(-value);
             }

            /**
             * Conversion operator
             * @return the value of the quantity in the specified unit
             */
            constexpr double to(const BaseUnit& a) const{
                if(!sameDim(a)){
                    throw std::invalid_argument("Dimensions do not match");
                }
                return value / a.val();
            }

            constexpr double val() const{
                return value;
            }
        };

        //Defining unit types
        #define DEFINE_NEW_UNIT(_Ldim, _Mdim, _tdim, _Qdim, _Tdim, _Ndim, _Jdim, _Adim, name) \
            typedef BaseUnit<std::ratio<_Ldim>, std::ratio<_Mdim>, std::ratio<_tdim>, std::ratio<_Qdim>, \
                std::ratio<_Tdim>, std::ratio<_Ndim>, std::ratio<_Jdim>, std::ratio<_Adim>> name;

        //Unitless type
        DEFINE_NEW_UNIT(0, 0, 0, 0, 0, 0, 0, 0, Number)
        constexpr Number number(1.0);

    } // Units
} // LouLib

#endif //LOULIB_BASEUNIT_HPP
