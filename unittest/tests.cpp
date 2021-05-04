#include <cstring>
#include "catch.hpp"
#include "../include/7Segment.h"
#include "../include/DigitFormatter.h"


TEST_CASE( "format rows", "DigitFormatter" ) {
    SECTION("print Single Digit Row") {
        char dst[4] = "";
        DigitFormatter::printDigitRow(dst, 5, 0);
        REQUIRE(strcmp(dst, " - ") == 0);
        DigitFormatter::printDigitRow(dst, 8, 1);
        REQUIRE(strcmp(dst, "| |") == 0);
        DigitFormatter::printDigitRow(dst, 4, 4);
        REQUIRE(strcmp(dst, "   ") == 0);
    }
    SECTION("print Whole Row") {
        char dst[13] = "";
        DigitFormatter::printWholeRow(dst, 0, 0,1,2);
        REQUIRE(strcmp(dst, " -       - \n") == 0);
    }
}

TEST_CASE( "String is correct", "MultiDigit" ) {
    SECTION("single digit") {
        MultiDigit number{8};
        REQUIRE(strcmp(number, " - \n| |\n - \n| |\n - \n") == 0);
    }
    SECTION("multiple digits") {
        MultiDigit number{1,2,3};
        REQUIRE(strcmp(number, "     -   - \n  |   |   |\n     -   - \n  | |     |\n     -   - \n") == 0);
    }
}
