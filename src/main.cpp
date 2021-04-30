#include "../include/7Segment.h"
#include <cstdio>

int main() {

    constexpr MultiDigit test{0,1,2,3,4,5,6,7,8,9};

    const char* string = test;

    printf("%s",string);
}
