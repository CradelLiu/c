//对10个数组元素依次赋值为0，1，2，3，4，5，6，7，8，9，要求按逆序输出
int example_6_1() {
    int i, a[10];
    for (i = 9; i >= 0; i--) {
        a[i] = i;
        printf("%d\t", a[i]);
    }
}

//用数组来处理求Fibonacci数列问题
void example_6_2() {
    int i;
    int f[20] = {1, 1};
    //赋值
    for (i = 2; i < 20; i++)
        f[i] = f[i - 2] + f[i - 1];
    //输出
    for (i = 0; i < 20; i++) {
        if (i % 5 == 0) printf("\n");
        printf("%12d", f[i]);
    }
}

//有10个地区的面积，要求对它们按由小到大的顺序排列
void example_6_3() {
    int a[10];
    printf("input 10 numbers:\n");
    for (int i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    printf("\n");
    bubbleSort(a, sizeof(a) / sizeof(a[0]));
    printf("the sorted numbers:\n");
    for (int i = 0; i <= 9; i++)
        printf("%d", a[i]);
}

//将一个二维数组行和列的元素互换，存到另一个二维数组中
void example_6_4() {
    int a[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
    };
    int b[3][2], i, j;
    printf("array a:\n");
    for (i = 0; i <= 1; i++)
        for (j = 0; j <= 2; j++) {
            printf("%5d", a[i][j]);
            b[j][i] = a[i][j];
        }
    printf("array b:\n");
    for (i = 0; i <= 2; i++)
        for (j = 0; j <= 1; j++)
            printf("%5d", b[i][j]);
}

//有一个3×4的矩阵，求出其中值最大的那个元素的值，及其所在的行号和列号
void example_6_5() {
    int i, j, row = 0, colum = 0, max;
    int a[3][4] = {
            {1,   2,  3,  4},
            {9,   8,  7,  6},
            {-10, 10, -5, 2}
    };
    max = a[0][0];
    for (i = 0; i <= 2; i++)
        for (j = 0; j <= 3; j++)
            if (a[i][j] > max) {
                max = a[i][j];
                row = i;
                colum = j;
            }
    printf("max=%d\nrow=%d\ncolum=%d\n", max, row, colum);
}

//输入一行字符，统计其中有多少个单词，单词之间用空格分隔开
void example_6_8() {
    char string[81];
    int i, num = 0, wordFlag = 0;
    char c;
    gets(string);
    for (i = 0; (c = string[i] != '\0'); i++)
        if (c == ' ') wordFlag = 0;
        else if (wordFlag == 0) {
            wordFlag = 1;
            num++;
        }
    printf("There are %d words in this line.\n", num);
}

//有3个字符串，找出其中最大者
#include "string.h"

void example_6_9() {
    char str[3][20];
    char string[20];
    int i;
    //输入3个字符串
    for (i = 0; i < 3; i++)
        gets(str[i]);
    //比较，相等得0，大于为正，小于为负
    //以第一对不相同的字符的比较结果为准
    //比较方式：英文词典中位置在后面的大 所有小写字母比所有大写字母大
    //先取str[0]和str[1]中最大值
    if (strcmp(str[0], str[1]) > 0)
        strcpy(string, str[0]); //将参数2复制到参数1中
    else
        strcpy(string, str[1]);
    //再和str[2]比较判断
    if (strcmp(str[2], string) > 0)
        strcpy(string, str[2]);
    printf("\nthe largest string is:\n%%s\n", string);
}
