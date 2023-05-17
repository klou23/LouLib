#ifndef LOULIB_ABSTRACTFILTER_HPP
#define LOULIB_ABSTRACTFILTER_HPP

namespace LouLib {
    namespace Filters {

        class AbstractFilter {
        public:
            virtual void addReading(double reading) = 0;

            virtual double getOutput() = 0;
        };

    } // LouLib
} // Filters

#endif //LOULIB_ABSTRACTFILTER_HPP
