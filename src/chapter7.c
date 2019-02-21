//有5个学生坐在一起，问第5个学生多少岁，他说比第4个学生大2岁。问第4个学生岁数，他说比第3个学生大2岁。问第3个学生，又说比第2个学生大2岁。问第2个学生，说比第1个学生大2岁。最后问第1个学生，他说是10岁。请问第5个学生多大。
int age(int n) {
    int result;
    if (n == 1)
        result = 10;
    else
        result = age(n - 1) + 2;
    return result;
}

void example_7_6() {
    printf("NO.5,age:%d\n", age(5));
}

//用递归方法求n的阶乘
int fac(int n) {
    int f;
    if (n < 0)
        printf("n<0,data error!");
    else if (n == 0 || n == 1)
        f = 1;
    else f = n * fac(n - 1);
}

void example_7_7() {
    int n;
    printf("input an integer number:");
    scanf("%d", &n);
    printf("%d!=%d\n", n, fac(n));
}

//Hanoi(汉诺)塔问题
//直接移动
void move(char x, char y) {
    printf("%c->%c\n", x, y);
}

//将n个盘从one座借助two座，移动到three座
void hanoi(int n, char one, char two, char three) {
    if (n == 1)
        move(one, three);
    else {
        //把上面n-1个盘子借助three座移动到two座
        hanoi(n - 1, one, three, two);
        //把底下的1个盘子直接移动到three座
        move(one, three);
        //把上面n-1个盘子借助one座移动到three座
        hanoi(n - 1, two, one, three);
    }
}

void example_7_8() {
    int diskCount;
    printf("input the number of diskes:");
    scanf("%d", &diskCount);
    printf("The step to move %d diskes:\n", diskCount);
    hanoi(diskCount, 'A', 'B', 'C');
}

//数组元素作为函数参数
//输入10个数，输出其中值最大的元素和该数是第几个数
int max(int x, int y) {
    return (x > y ? x : y);
}

void example_7_9() {
    int a[10], largestNumber, n, i;
    printf("enter 10 integer numbers:");
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    printf("\n");
    for (i = 1, largestNumber = a[0], n = 0; i < 10; i++) {
        if (max(largestNumber, a[i]) > largestNumber) {
            largestNumber = max(largestNumber, a[i]);
            n = i;
        }
    }
    printf("The largest number is %d\nit is the %dth number.\n", largestNumber, n + 1);
}

//数组名作为函数参数
//有一个一维数组score，里面放了10个学生成绩，求平均成绩
float average(float arr[], int len) {
    float aver, sum = 0;
    for (int i = 0; i < len; i++)
        sum += arr[i];
    aver = sum / 10;
    return aver;
}

void example_7_10() {
    float score[10];
    printf("input 10 score:\n");
    for (int i = 0; i < 10; i++)
        printf("%f", &score[i]);
    printf("\naverage score is %5.2f\n", average(score, sizeof(score) / sizeof(score[0])));
}

//有两个班级，分别有35和30名学生，调用一个average函数，分别求这两个班的学生的平均成绩
void example_7_11() {
    float score1[5] = {98.5, 97, 91.5, 60, 55};
    float score2[10] = {67.5, 89.5, 99, 69.5, 77, 89.5, 76.5, 54, 60, 99.5};
    printf("The average of class A is %6.2f\n", average(score1, sizeof(score1) / sizeof(score1[0])));
    printf("The average of class B is %6.2f\n", average(score2, sizeof(score2) / sizeof(score2[0])));
}

//选择排序
void example_7_12() {
    int a[10], i;
    printf("enter array:\n");
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    selectionSort(a, 10);
}

//有一个3×4的矩阵，求所有元素中的最大值
int max_value(int arr[][4]) {
    int i, j, max;
    max = arr[0][0];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
            if (arr[i][j] > max) max = arr[i][j];
    return max;
}

void example_7_13() {
    int a[3][4] = {
            {1,  3,  5,  7},
            {2,  4,  6,  8},
            {15, 17, 34, 12},
    };
    printf("Max value is %d\n", max_value(a));
}

//全局变量
//有一个一维数组，内放10个学生成绩，写一个函数，当主函数调用此函数后，能求出平均分、最高分和最低分
float Max = 0, Min = 0;

float average_7_14(float arr[], int n) {
    int i;
    float aver, sum = 0;
    Max = Min = arr[0];
    for (i = 0; i < n; i++) {
        if (arr[i] > Max) Max = arr[i];
        else if (arr[i] < Min) Min = arr[i];
        sum += arr[i];
    }
    aver = sum / n;
    return aver;
}

void example_7_14() {
    float ave, score[10];
    int i;
    printf("Please enter 10 scores:");
    for (i = 0; i < 10; i++) {
        scanf("%df", &score[i]);
        ave = average_7_14(score, 10);
    }
    printf("max=%6.2f\nmin=%6.2f\naverage=%6.2f\n", Max, Min, ave);
}

//若外部变量与局部变量同名，全局变量被局部变量覆盖
int a = 3, b = 5;

int max_7_15(int a, int b) {
    int c;
    c = a > b ? a : b;
    return c;
}

void example_7_15() {
    int a = 8;
    printf("max=%d\n", max_7_15(a, b));
}

//静态局部变量
int f(int a) {
    auto int b = 0;
    static c = 3;
    b = b + 1;
    c = c + 1;
    return a + b + c;
}

void example_7_16() {
    int a = 2, i;
    for (i = 0; i < 3; i++)
        printf("%d\n", f(a));
}

//静态局部变量
//输出1到5的阶乘值
int fac_7_17(int n) {
    static int f = 1;
    f = f * n;
    return f;
}

void example_7_17() {
    for (int i = 0; i <= 5; i++)
        printf("%d!=%d\n", i, fac_7_17(i));
}

//在一个文件内扩展外部变量的作用域
void example_7_18() {
    int max_7_18();
    extern int A, B, C;
    printf("Please enter three integer numbers:");
    scanf("%d %d %d", &A, &B, &C);
    printf("max is %d\n", max_7_18());
}

int A, B, C;

int max_7_18() {
    int m;
    m = A > B ? A : B;
    if (C > m) m = C;
    return m;
}
