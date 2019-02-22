#include "stdio.h"
#include "math.h"

//求1累加到100
void example_5_1() {
    int i = 1, sum = 0;
    while (i <= 100) {
        sum += i;
        i++;
    }
    printf("sum=%d\n", sum);
}

//用do...while语句求1加到100
void example_5_2() {
    int i = 1, sum = 0;
    do {
        sum = sum + i;
        i++;
    } while (i <= 100);
    printf("sum=%d\n", sum);
}

//在全系1000学生中，征集慈善募捐，当总数达到10万元时就结束，统计此时捐款的人数，以及平均每人捐款的数目
#define SUM 100000

void example_5_4() {
    float amount, aver, total;
    int i;
    for (i = 1, total = 0; i <= 1000; i++) {
        printf("please enter amount:");
        scanf("%f", &amount);
        total += amount;
        if (total >= SUM) break;
    }
    aver = total / i;
    printf("num=%d\naver=%10.2f\n", i, aver);
}

//输出100~200之间的每一个整数进行检查，如果不能被3整除，就将此数输出，若能被3整除，就不输出此数。无论是否输出此数，都要接着检查下一个数（直到200为止）。
void example_5_5() {
    int n;
    for (n = 100; n <= 200; n++) {
        if (n % 3 == 0)
            continue;
        printf("%d", n); //%d：按整型数据十进制的实际长度输出
    }
}

//输出矩阵（嵌套循环）
void example_5_6() {
    int i, j = 0;
    for (i = 1; i <= 4; i++)
        for (j = 1; j <= 5; j++) {
            printf("%d\t", i * j);
            if (j == 5) printf("\n");
        }
}

void example_5_7() {

}

//求Fibonacci数列的前40个数。这个数列有如下特点：第1，2两个数为1。从第三个数开始，该数是其前面两个数之和。即：
//举例：有一对兔子，从出生后第3个月起每个月都生一对兔子。小兔子长到第三个月后每个月又生一对兔子。假设所有的兔子都不死，问每个月的兔子总数为多少？
void example_5_8() {
    int f1 = 1, f2 = 1, f3;
    int i;
    printf("%12d\n%12d\n", f1, f2); //统一%12d是为了对齐
    for (i = 3; i <= 40; i++) {
        f3 = f1 + f2;
        printf("%12d\n", f3);
        f1 = f2;
        f2 = f3;
    }
}

//输入一个大于3的整数n，判定它是否为素数（prime，又称质数）
void example_5_9() {
    int n, i;
    while (1) {
        printf("please enter a integer number,n=?");
        scanf("%d", &n);
        for (i = 2; i <= n - 1; i++)
            if (n % i == 0) break;
        if (i == n)
            printf("%d is a prime number\n", n);
        else
            printf("%d is not a prime number\n", n);
    }
}

//求100~200间的全部素数
void example_5_10() {
    int n, k, i, m = 0;
    //偶数不是素数
    for (n = 101; n <= 200; n += 2) {
        k = sqrt(n);
        for (i = 2; i <= k; i++)
            if (n % i == 0) break;
        if (i == k + 1) {
            printf("%d\t", n);
            m += 1;
        }
        if (m % 10 == 0) printf("\n"); //每行显示10个
    }
}

//译密码
void example_5_11() {
    char c;
    //c = getchar(); //一次性输入多个字符，按下回车时，顺次将字符赋值给c
    while ((c = getchar()) != '\n') {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if ((c >= 'w' && c <= 'z') || (c >= 'W' && c <= 'Z')) c -= 22;
            else c += 4;
        }
        printf("%c", c);
        //c = getchar(); //将后面的字符赋值给c
    }
}