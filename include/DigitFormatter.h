//
// Created by nicom on 30.04.2021.
//

#ifndef UEBUNG04_DIGITFORMATTER_H
#define UEBUNG04_DIGITFORMATTER_H


class DigitFormatter {
public:

    template <typename  T, typename... Args>
    static constexpr char* printWholeRow(char* dst, int row, T first, Args... args) {
        dst = DigitFormatter::printDigitRow(dst, first, row);

        if(sizeof...(Args) > 0) {

            *dst = ' ';
            ++dst;
            dst = printWholeRow(dst, row, args...);
        }
        else {
            *dst = '\n';
            ++dst;
        }
        return dst;
    }

    static constexpr char* printWholeRow(char* dst, int) { return dst; }

    static constexpr char* printDigitRow(char* dst, int digit, int row) {
        if(dst == nullptr || row < 0 || row >= 5) return dst;
        if(digit > 9 || digit < 0) { digit = fallback_number(); }

        for(int col = 0; col < 3; col++) {
            int segmentNumber = _formation[row][col];
            if(segmentNumber == -1) { *dst = ' '; }
            else { *dst = _symbol[digit][segmentNumber]; }
            ++dst;
        }
        *dst = '\0';
        return dst;
    }

    // function gets called when if the digit is <0 or >9. It returns an alternative digit to print.
    // The function is intentionally not constexpr so the compiler throws an Error when
    // MultiDigit is initialized constexpr with illegal numbers.
    // e.g. constexpr MultiDigit a{1,2,14} -> Compile-Time Error
    //                MultiDigit b{1,2,14} -> use fallback_number to prevent segmentation fault
    static int fallback_number() {
        return 0;
    }

private:
    // holds the symbol that should be printed for a given digit and a given segment index.
    constexpr static char _symbol[10][7] = {     // digit     segment
            {'-', '|', '|', ' ', '|', '|', '-'}, //   0       ---0---
            {' ', ' ', '|', ' ', ' ', '|', ' '}, //   1      |       |
            {'-', ' ', '|', '-', '|', ' ', '-'}, //   2      1       2
            {'-', ' ', '|', '-', ' ', '|', '-'}, //   3      |       |
            {' ', '|', '|', '-', ' ', '|', ' '}, //   4       ---3---
            {'-', '|', ' ', '-', ' ', '|', '-'}, //   5      |       |
            {'-', '|', ' ', '-', '|', '|', '-'}, //   6      4       5
            {'-', ' ', '|', ' ', ' ', '|', ' '}, //   7      |       |
            {'-', '|', '|', '-', '|', '|', '-'}, //   8       ---6---
            {'-', '|', '|', '-', ' ', '|', '-'}  //   9
    };
    // holds the formation of segments for a given row. -1 represents blank space
    constexpr static int _formation[5][3] = {
            {-1,  0, -1},
            { 1, -1,  2},
            {-1,  3, -1},
            { 4, -1,  5},
            {-1,  6, -1}
    };
};

#endif //UEBUNG04_DIGITFORMATTER_H
