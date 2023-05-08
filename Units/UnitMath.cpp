/**
 * UnitMath.cpp
 *
 * Contains implementations for mathematical operators for units
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

#include <cmath>
#include "UnitMath.hpp"

namespace LouLib{
    namespace Units{

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr BaseUnit<L, M, t, Q, T, N, J, A> operator+(
                const BaseUnit<L, M, t, Q, T, N, J, A>& a,
                const BaseUnit<L, M, t, Q, T, N, J, A>& b
        ){
            return BaseUnit<L, M, t, Q, T, N, J, A>(a.val() + b.val());
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr BaseUnit<L, M, t, Q, T, N, J, A> operator-(
                const BaseUnit<L, M, t, Q, T, N, J, A>& a,
                const BaseUnit<L, M, t, Q, T, N, J, A>& b
        ){
            return BaseUnit<L, M, t, Q, T, N, J, A>(a.val() - b.val());
        }

        template<typename L1, typename M1, typename t1, typename Q1,
                typename T1, typename N1, typename J1, typename A1,
                typename L2, typename M2, typename t2, typename Q2,
                typename T2, typename N2, typename J2, typename A2>
        constexpr BaseUnit<std::ratio_add<L1, L2>,
                std::ratio_add<M1, M2>,
                std::ratio_add<t1, t2>,
                std::ratio_add<Q1, Q2>,
                std::ratio_add<T1, T2>,
                std::ratio_add<N1, N2>,
                std::ratio_add<J1, J2>,
                std::ratio_add<A1, A2>> operator *(
                const BaseUnit<L1, M1, t1, Q1, T1, N1, J1, A1>& a,
                const BaseUnit<L2, M2, t2, Q2, T2, N2, J2, A2>& b
        ){
            return BaseUnit<std::ratio_add<L1, L2>,
                            std::ratio_add<M1, M2>,
                            std::ratio_add<t1, t2>,
                            std::ratio_add<Q1, Q2>,
                            std::ratio_add<T1, T2>,
                            std::ratio_add<N1, N2>,
                            std::ratio_add<J1, J2>,
                            std::ratio_add<A1, A2>>(a.val() * b.val());
        }

        template<typename L1, typename M1, typename t1, typename Q1,
                typename T1, typename N1, typename J1, typename A1,
                typename L2, typename M2, typename t2, typename Q2,
                typename T2, typename N2, typename J2, typename A2>
        constexpr BaseUnit<std::ratio_subtract<L1, L2>,
                std::ratio_subtract<M1, M2>,
                std::ratio_subtract<t1, t2>,
                std::ratio_subtract<Q1, Q2>,
                std::ratio_subtract<T1, T2>,
                std::ratio_subtract<N1, N2>,
                std::ratio_subtract<J1, J2>,
                std::ratio_subtract<A1, A2>> operator /(
                const BaseUnit<L1, M1, t1, Q1, T1, N1, J1, A1>& a,
                const BaseUnit<L2, M2, t2, Q2, T2, N2, J2, A2>& b
        ){
            BaseUnit<std::ratio_subtract<L1, L2>,
                     std::ratio_subtract<M1, M2>,
                     std::ratio_subtract<t1, t2>,
                     std::ratio_subtract<Q1, Q2>,
                     std::ratio_subtract<T1, T2>,
                     std::ratio_subtract<N1, N2>,
                     std::ratio_subtract<J1, J2>,
                     std::ratio_subtract<A1, A2>>(a.val() / b.val());
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr BaseUnit<L, M, t, Q, T, N, J, A> operator*(
                const double& a,
                const BaseUnit<L, M, t, Q, T, N, J, A>& b
        ){
            return BaseUnit<L, M, t, Q, T, N, J, A>(a * b.val());
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr BaseUnit<L, M, t, Q, T, N, J, A> operator*(
                const BaseUnit<L, M, t, Q, T, N, J, A>& a,
                const double& b
        ){
            return BaseUnit<L, M, t, Q, T, N, J, A>(b * a.val());
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr BaseUnit<L, M, t, Q, T, N, J, A> operator/(
                const BaseUnit<L, M, t, Q, T, N, J, A>& a,
                const double& b
        ){
            return BaseUnit<L, M, t, Q, T, N, J, A>(a.val() / b);
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr BaseUnit<std::ratio_subtract<std::ratio<0>, L>,
                std::ratio_subtract<std::ratio<0>, M>,
                std::ratio_subtract<std::ratio<0>, t>,
                std::ratio_subtract<std::ratio<0>, Q>,
                std::ratio_subtract<std::ratio<0>, T>,
                std::ratio_subtract<std::ratio<0>, N>,
                std::ratio_subtract<std::ratio<0>, J>,
                std::ratio_subtract<std::ratio<0>, A>> operator /(
                const double& a,
                const BaseUnit<L, M, t, Q, T, N, J, A>& b
        ){
            return BaseUnit<std::ratio_subtract<std::ratio<0>, L>,
                            std::ratio_subtract<std::ratio<0>, M>,
                            std::ratio_subtract<std::ratio<0>, t>,
                            std::ratio_subtract<std::ratio<0>, Q>,
                            std::ratio_subtract<std::ratio<0>, T>,
                            std::ratio_subtract<std::ratio<0>, N>,
                            std::ratio_subtract<std::ratio<0>, J>,
                            std::ratio_subtract<std::ratio<0>, A>>(a / b.val());
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr BaseUnit<L, M, t, Q, T, N, J, A> operator%(
                const BaseUnit<L, M, t, Q, T, N, J, A>& a,
                const BaseUnit<L, M, t, Q, T, N, J, A>& b
        ){
            return BaseUnit<L, M, t, Q, T, N, J, A>(std::fmod(a.val(), b.val()));
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr bool operator==(
                const BaseUnit<L, M, t, Q, T, N, J, A>& a,
                const BaseUnit<L, M, t, Q, T, N, J, A>& b
        ){
            return a.val() == b.val();
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr bool operator!=(
                const BaseUnit<L, M, t, Q, T, N, J, A>& a,
                const BaseUnit<L, M, t, Q, T, N, J, A>& b
        ){
            return a.val() != b.val();
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr bool operator>(
                const BaseUnit<L, M, t, Q, T, N, J, A>& a,
                const BaseUnit<L, M, t, Q, T, N, J, A>& b
        ){
            return a.val() > b.val();
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr bool operator<(
                const BaseUnit<L, M, t, Q, T, N, J, A>& a,
                const BaseUnit<L, M, t, Q, T, N, J, A>& b
        ){
            return a.val() < b.val();
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr bool operator>=(
                const BaseUnit<L, M, t, Q, T, N, J, A>& a,
                const BaseUnit<L, M, t, Q, T, N, J, A>& b
        ){
            return a.val() >= b.val();
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr bool operator<=(
                const BaseUnit<L, M, t, Q, T, N, J, A>& a,
                const BaseUnit<L, M, t, Q, T, N, J, A>& b
        ){
            return a.val() <= b.val();
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr BaseUnit<L, M, t, Q, T, N, J, A> abs(
                BaseUnit<L, M, t, Q, T, N, J, A>& a
        ){
            return BaseUnit<L, M, t, Q, T, N, J, A>(std::abs(a.val()));
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr BaseUnit<std::ratio_divide<L, std::ratio<2>>,
                std::ratio_divide<M, std::ratio<2>>,
                std::ratio_divide<t, std::ratio<2>>,
                std::ratio_divide<Q, std::ratio<2>>,
                std::ratio_divide<T, std::ratio<2>>,
                std::ratio_divide<N, std::ratio<2>>,
                std::ratio_divide<J, std::ratio<2>>,
                std::ratio_divide<A, std::ratio<2>>> sqrt(
                BaseUnit<L, M, t, Q, T, N, J, A>& a
        ){
            return BaseUnit<std::ratio_divide<L, std::ratio<2>>,
                    std::ratio_divide<M, std::ratio<2>>,
                    std::ratio_divide<t, std::ratio<2>>,
                    std::ratio_divide<Q, std::ratio<2>>,
                    std::ratio_divide<T, std::ratio<2>>,
                    std::ratio_divide<N, std::ratio<2>>,
                    std::ratio_divide<J, std::ratio<2>>,
                    std::ratio_divide<A, std::ratio<2>>>(std::sqrt(a.val()));
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr BaseUnit<std::ratio_multiply<L, std::ratio<2>>,
                std::ratio_multiply<M, std::ratio<2>>,
                std::ratio_multiply<t, std::ratio<2>>,
                std::ratio_multiply<Q, std::ratio<2>>,
                std::ratio_multiply<T, std::ratio<2>>,
                std::ratio_multiply<N, std::ratio<2>>,
                std::ratio_multiply<J, std::ratio<2>>,
                std::ratio_multiply<A, std::ratio<2>>> square(
                BaseUnit<L, M, t, Q, T, N, J, A>& a
        ){
            return BaseUnit<std::ratio_multiply<L, std::ratio<2>>,
                    std::ratio_multiply<M, std::ratio<2>>,
                    std::ratio_multiply<t, std::ratio<2>>,
                    std::ratio_multiply<Q, std::ratio<2>>,
                    std::ratio_multiply<T, std::ratio<2>>,
                    std::ratio_multiply<N, std::ratio<2>>,
                    std::ratio_multiply<J, std::ratio<2>>,
                    std::ratio_multiply<A, std::ratio<2>>>(a.val() * a.val());
        }

        template<typename L, typename M, typename t, typename Q,
                typename T, typename N, typename J, typename A>
        constexpr int signum(const BaseUnit<L, M, t, Q, T, N, J, A>& a){
            if(a.val() == 0) return 0;
            return a.val() > 0 ? 1 : -1;
        }

    }
}