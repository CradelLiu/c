#include <stdio.h>
#include "math.h"

//输入两个实数，按代数值由小到大的顺序输出这两个数
int example2() {
    float a, b, t;
    scanf("%f,%f", &a, &b);
    /*
        &是取地址符
        变量的值和地址是两个东西，赋值表达式右边是值，左边是地址
        在c中，写需要地址，读只需要值
    */
    if (a > b) {
        t = a;
        a = b;
        b = t;
    }
    printf("%5.2f,%5.2f\n", a, b);
    return 0;
}

//输入3个数a,b,c，要求按由小到大的顺序输出
int example3() {
    float a, b, c, t;
    scanf("%f,%f,%f", &a, &b, &c);
    if (a > b) {
        t = a;
        a = b;
        b = t;
    }
    if (a > c) {
        t = a;
        a = c;
        c = t;
    }
    if (b > c) {
        t = b;
        b = c;
        c = t;
    }
    printf("%5.2f,%5.2f,%5.2f\n", a, b, c);
}

//要求按照考试成绩的等级输出百分制分数段，A等为85分以上，B等为70~84分，C等为60~69分，D等为60分以下。成绩的等级由键盘输入。
int example6() {
    char grade;
    scanf("%c", &grade);
    printf("Your score:");
    switch (grade) {
        case 'A':
            printf("85~100\n");
            break;
        case 'B':
            printf("70~84\n");
            break;
        case 'C':
            printf("60~69\n");
            break;
        case 'D':
            printf("60分以下\n");
            break;
        default:
            printf("enter data error!\n");
    }
    return 0;
}

//*用switch语句处理菜单命令。在许多应用程序中，用菜单对流程进行控制，例如从键盘输入一个'A'或'a'字符，就会执行A操作，输入一个'B'或'b'字符，就会执行B操作。可以按以下思路编写程序。
int example7() {
    void action1(int, int), action2(int, int);
    char ch;
    int a = 15, b = 23;
    ch = getchar();
    switch (ch) {
        case 'a':
        case 'A':
            action1(a, b);
            break;
        case 'b':
        case 'B':
            action2(a, b);
            break;
        default:
            putchar('\a');
    }
}

void action1(int x, int y) {
    printf("x+y=%d\n", x + y);
}

void action2(int x, int y) {
    printf("x*y=%d\n", x * y);
}

//写一程序，判断某一年是否为闰年
//1.能被4整除而不能被100整除
//2.能被400整除
int example8() {
    int year;
    printf("enter year:");
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        printf("闰年");
    else
        printf("平年");
}

//求ax2+bx+c=0方程的解
void example9() {

}

int main() {
    example7();
}