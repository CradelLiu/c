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
float average(float arr[]) {
    float aver, sum = 0;
    for (int i = 0; i < sizeof(arr); i++)
        sum += arr[i];
    aver = sum / 10;
    return aver;
}

void example_7_10() {
    float score[10];
    printf("input 10 score:\n");
    for (int i = 0; i < 10; i++)
        printf("%f", &score[i]);
    printf("\naverage score is %5.2f\n", average(score));
}

//有两个班级，分别有35和30名学生，调用一个average函数，分别求这两个班的学生的平均成绩
void example_7_11() {
    float score1[5] = {98.5, 97, 91.5, 60, 55};
    float score2[10] = {67.5, 89.5, 99, 69.5, 77, 89.5, 76.5, 54, 60, 99.5};
    printf("The average of class A is %6.2f\n", average(score1));
    printf("The average of class B is %6.2f\n", average(score2));
}

//用选择法对数组中10个整数按由小到大排序
void sort(int arr[], int n) {
    int i, j, k, t;
    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[k])
                k = j;
        arr[i] += arr[k];
        arr[k] = arr[i] - arr[k];
        arr[i] = arr[i] - arr[k];
    }
}

void example_7_12() {
    int a[10], i;
    printf("enter array:\n");
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    sort(a, 10);
    printf("The sorted array:\n");
    for (i = 0; i < 10; i++)
        printf("%d", a[i]);
}