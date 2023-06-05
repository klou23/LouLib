/**
 * @file SMMFilter.cpp
 *
 * Implementation file for the SMMFilter class
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

#include "SMMFilter.hpp"

namespace LouLib {
    namespace Filters {

        SMMFilter::SMMFilter(int readingCount) : readingCount(readingCount) {}

        void SMMFilter::addReading(double reading) {
            sortedData.insert(reading);
            data.push(reading);
            if(data.size() > readingCount){
                sortedData.erase(sortedData.find(data.front()));
                data.pop();
            }
        }

        double SMMFilter::getOutput() {
            int n = (int) sortedData.size();

            auto iter = sortedData.begin();
            std::advance(iter, n/2);

            if(n%2 == 0){
                auto iter2 = iter--;
                return double(*iter + *iter2) / 2;
            }else{
                return *iter;
            }
        }


    } // LouLib
} // Filters