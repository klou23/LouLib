/**
 * @file Logger.hpp
 *
 * Header file for the Logger class
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

#ifndef LOULIB_LOGGER_HPP
#define LOULIB_LOGGER_HPP

#include <fstream>
#include <string>

namespace LouLib{
    namespace Utility{

        /**
         * @class Logger
         * @brief Class used to log data to micro-SD card
         */
        class Logger {
        private:
            std::ofstream fout;

        public:

            /**
             * Constructor
             */
            Logger();

            /**
             * Constructor
             * @param logFile
             * @param fileType
             */
            Logger(std::string logFile, std::string fileType = "txt");

            /**
             * Logs a new message to the file
             * @param message the message to be logged
             * @param endl whether or not to add a new line after the message
             */
            void log(std::string message, bool endl = false);

            /**
             * Closes the logger
             */
            void close();
        };
    }
}


#endif //LOULIB_LOGGER_HPP
