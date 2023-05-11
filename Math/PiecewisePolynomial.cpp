/**
 * PiecewisePolynomial.cpp
 *
 * Implementation file for the PiecewisePolynomial class
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

#include "PiecewisePolynomial.hpp"

namespace LouLib{
    namespace Math{
        void PiecewisePolynomial::insert(PiecewisePolynomialPart p) {
            int l = 0;
            int r = (int) pieces.size()-1;
            while(l < r){
                int mid = l + (r-l)/2;
                if(pieces[mid].getStart() < p.getStart()){
                    l = mid+1;
                }else if(pieces[mid].getStart() > p.getStart()){
                    r = mid;
                }else{
                    throw std::invalid_argument("Sub-function domain intersects with the domain of another");
                }
            }

            if(l > 0 && pieces[l-1].getEnd() > p.getStart()){
                throw std::invalid_argument("Sub-function domain intersects with the domain of another");
            }else if(pieces[l].getStart() < p.getEnd()){
                throw std::invalid_argument("Sub-function domain intersects with the domain of another");
            }

            pieces.insert(pieces.begin()+l, p);

        }

        PiecewisePolynomial::PiecewisePolynomial() = default;

        PiecewisePolynomial::PiecewisePolynomial(std::vector<PiecewisePolynomialPart> p) {
            for(const PiecewisePolynomialPart& part : p){
                insert(part);
            }
        }

        PiecewisePolynomialPart PiecewisePolynomial::getPart(double x) {
            int l = 0;
            int r = (int) pieces.size()-1;
            while(l < r){
                int mid = l + (r-l)/2;
                if(pieces[mid].getEnd() < x){
                    l = mid+1;
                }else if(pieces[mid].getStart() > x){
                    r = mid-1;
                }else{
                    return pieces[mid];
                }
            }

            if(pieces[l].getStart() <= x && x <= pieces[l].getEnd()){
                return pieces[l];
            }else{
                throw std::invalid_argument("No valid polynomial part");
            }
        }

        double PiecewisePolynomial::evaluate(double x) {
            PiecewisePolynomialPart p = getPart(x);
            return p.evaluate(x);
        }

    }
}





