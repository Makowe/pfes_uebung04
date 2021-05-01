#include "../include/7Segment.h"
#include <cstdio>

int main() {
    MultiDigit test{0,1,2,3,4,5,6,7,8,9};
    const char* string = test;
    printf("%s",string);

    MultiDigit test2{-4,1,12,2};
    const char* string2 = test2;
    printf("%s",string2);
}
