/**
 * @file SMMFilter.hpp
 *
 * Header file for the SMMFilter class
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

#ifndef LOULIB_SMMFILTER_HPP
#define LOULIB_SMMFILTER_HPP

#include <queue>
#include <set>
#include "AbstractFilter.hpp"
#include <ext/pb_ds/assoc_container.hpp>

namespace LouLib {
    namespace Filters {

        /**
         * @class SMMFilter
         * @brief Class used as a simple moving median filter
         */
        class SMMFilter : public AbstractFilter{
        private:
            int readingCount;
            std::queue<double> data;
            __gnu_pbds::tree<std::pair<double,int>, __gnu_pbds::null_type, std::less<>,
                    __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> sortedData;
            int ostCounter = 0;

        public:

            /**
             * Constructor
             * @param readingCount number of readings to find the median of
             */
            explicit SMMFilter(int readingCount);

            /**
             * Adds a new reading into the filter's data set
             */
            void addReading(double reading) override;

            /**
             * Returns the output value of the filter
             */
            double getOutput();

        };

    } // LouLib
} // Filters

#endif //LOULIB_SMMFILTER_HPP
