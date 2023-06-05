/**
 * @file Logger.cpp
 *
 * Implementation file for the Logger class
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

#include "Logger.hpp"
#include <iostream>

LouLib::Utility::Logger::Logger() : Logger("log", "txt"){}

LouLib::Utility::Logger::Logger(std::string logFile, std::string fileType) {
    std::ifstream check("/usd/" + logFile + "." + fileType);
    if(!check.good()){
        fout.open("/usd/" + logFile + "." + fileType);
    }else{
        int i = 0;
        do{
            i++;
            check.close();
            check.open("/usd/" + logFile + "(" + std::to_string(i) + ")." + fileType);
        }while(check.good());
        fout.open("/usd/" + logFile + "(" + std::to_string(i) + ")." + fileType);
    }
    fout.flush();
}

void LouLib::Utility::Logger::log(std::string message, bool endl) {
    fout << message;
    if(endl) fout << std::endl;
    fout.flush();
}

void LouLib::Utility::Logger::close() {
    fout.close();
}


