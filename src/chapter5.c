#include "stdio.h"

//求1累加到100
void example_5_1() {
    int i = 1, sum = 0;
    while (i <= 100) {
        sum += i;
        i++;
    }
    printf("sum=%d\n", sum);
}