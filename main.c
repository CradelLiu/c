#include "stdio.h"
#include "stdbool.h"
#include "math.h"

#include "src/dataStructure/sort.c"

//C语言
#include "src/basic/chapter4.c"
#include "src/basic/chapter5.c"
#include "src/basic/chapter6.c"
#include "src/basic/chapter7.c"

//数据结构
#include "src/dataStructure/chapter2.c"

int testArr[] = {12, 13, 23, 14, 16, 11};

int main() {
    SqList L;
    L.length = sizeof(testArr) / sizeof(testArr[0]);
    for (int i = 0; i < L.length; i++)
        L.data[i] = testArr[i];

    printf("%d", 6 < 5);
}