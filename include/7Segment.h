//
// Created by nicom on 29.04.2021.
//

#ifndef UEBUNG04_7SEGMENT_H
#define UEBUNG04_7SEGMENT_H
#include "DigitFormatter.h"


template<typename T, typename... Args>
class MultiDigit {
public:
    constexpr MultiDigit(T first, Args... args) :  _string("") {
        char* dst = _string;

        for(int row = 0; row < 5; ++row) {
            dst = DigitFormatter::printWholeRow(dst, row, first, args...);
        }
    }

    operator const char*() const { return _string; }

private:
    char _string[(sizeof...(Args)+1) * 20 +1];
};


#endif //UEBUNG04_7SEGMENT_H