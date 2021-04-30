//
// Created by nicom on 29.04.2021.
//

#ifndef UEBUNG04_7SEGMENT_H
#define UEBUNG04_7SEGMENT_H
#include "DigitFormatter.h"


template<typename T, typename... Args>
class MultiDigit {
public:
    constexpr MultiDigit(T first, Args... args) : _digits{first, args...}, _string("") {
        fillString();
    }

    operator const char*() const { return _string; }

private:
    constexpr void fillString();

    int _digits[sizeof...(Args) + 1];
    char _string[(sizeof...(Args)+1) * 20 +1];
};

template<typename T, typename... Args>
constexpr void MultiDigit<T, Args...>::fillString() {

    const int numDigits = sizeof...(Args)+1;
    char* dst = _string;

    for(int row = 0; row < 5; ++row) {

        for(int digit = 0; digit < numDigits; ++digit) {
            dst = DigitFormatter::printRow(dst, _digits[digit], row);
            if(digit < numDigits -1) { *dst = ' '; ++dst; }
        }
        *dst = '\n';
        ++dst;
    }
    *dst = '\0';
}

#endif //UEBUNG04_7SEGMENT_H