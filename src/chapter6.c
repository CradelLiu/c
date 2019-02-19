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
    int a[10], i, j, t;
    printf("input 10 numbers:\n");
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    printf("\n");
    for (j = 0; j < 9; j++)
        for (i = 0; i < 9 - j; i++)
            if (a[i] > a[i + 1]) { //不借助第三方变量的两个值交换
                a[i] += a[i + 1];
                a[i + 1] = a[i] - a[i + 1];
                a[i] = a[i] - a[i + 1];
            }
}