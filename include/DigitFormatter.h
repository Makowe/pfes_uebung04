//
// Created by nicom on 30.04.2021.
//

#ifndef UEBUNG04_DIGITFORMATTER_H
#define UEBUNG04_DIGITFORMATTER_H


class DigitFormatter {
public:
    static constexpr char* printRow(char* dst, int digit, int row);

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

constexpr char* DigitFormatter::printRow(char *dst, int digit, int row) {
    if(dst == nullptr || digit < 0 || digit >= 10 || row < 0 || row >= 5) return dst;

    for(int col = 0; col < 3; col++) {
        int segmentNumber = _formation[row][col];
        if(segmentNumber == -1) { *dst = ' '; }
        else { *dst = _symbol[digit][segmentNumber]; }
        ++dst;
    }
    *dst = '\0';
    return dst;
}

#endif //UEBUNG04_DIGITFORMATTER_H
