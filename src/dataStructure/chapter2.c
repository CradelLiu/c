bool p18q1(SqList L, int *min) {
    if (L.length <= 0) {
        printf("出错");
        return false;
    }
    *min = L.data[0];
    for (int i = 1; i < L.length; i++)
        if (L.data[i] < *min) {
            *min = L.data[i];
            L.data[i] = L.data[L.length - 1];
            L.length--;
        }
    return true;
}

void p18q2(SqList L) {
    for (int i = 0; i < L.length / 2; i++)
        swap(L.data, i, L.length - 1 - i);
    printArr(L.data, L.length);
}

void p18q3(SqList L, int x) {
    int k = 0;
    for (int i = 0; i < L.length; i++)
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;
        }
    L.length = k;
}

bool p18q4(SqList L, int s, int t) {
    if (s >= t || L.length == 0) return false;
    bubbleSort(L.data, L.length);

    int i, j; //i是待删元素的起始下标 j是待删元素的最后一个下标+1
    //定位i的值
    for (i = 0; i < L.length && L.data[i] < s; i++);
    if (i == L.length) return false; //如果s比所有元素都大 说明没有元素可删
    //定位j的值
    for (j = i; i < L.length && L.data[i] <= t; j++);
    for (; j < L.length; i++, j++)
        L.data[i] = L.data[j];

    L.length = i;
    printArr(L.data, L.length);
    return true;
}

bool p18q5(SqList L, int s, int t) {
    if (s >= t || L.length == 0) return false;

    int k = 0;
    for (int i = 0; i < L.length; i++)
        if (s <= L.data[i] && L.data <= t)
            k++;
        else
            L.data[i - k] = L.data[i];

    L.length -= k;
    printArr(L.data, L.length);
    return true;
}

bool p18q6(SqList L) {
    if (L.length == 0) return false;
    //i指向有序顺序表的最后一项
    int i, j;
    for (i = 0, j = 1; j < L.length; j++)
        if (L.data[i] != L.data[j])
            L.data[++i] = L.data[j];
    L.length = i + 1;
    return true;
}

bool p18q7(SqList A, SqList B, SqList C) {
    if (A.length + B.length > C.length) return false;
    int a = 0, b = 0, c = 0;
    while (a < A.length && b < B.length)
        C.data[c++] = A.data[a++] < B.data[b++] ? A.data[a] : B.data[b];
    while (a < A.length)
        C.data[c++] = A.data[a++];
    while (b < B.length)
        C.data[c++] = B.data[b++];
    C.length = c;
    return true;
}

bool p18q8(SqList L, int m) {
    for (int i = 0; i < L.length / 2; i++)
        swap(L.data, i, L.length - 1 - i);
    printArr(L.data, L.length);
    for (int i = 0; i < m / 2; i++)
        swap(L.data, i, m - 1 - i);
    printArr(L.data, L.length);
    for (int i = L.length - 1; i > m + m / 2; i--)
        swap(L.data, L.length - 1, m);
    printArr(L.data, L.length);
}

void p18q9(SqList L, int x) {
    int result = binarySearch(L.data, L.length, x);
    if (result != -1 && result + 1 < L.length)
        swap(L.data, result, result + 1);
    else
        for (int i = L.length - 1; i >= 0; i--) {
            if (x >= L.data[i]) {
                L.data[i + 1] = x;
                L.length++;
                break;
            } else
                L.data[i + 1] = L.data[i];
        }
    printArr(L.data, L.length);
}

//数组每一项元素循环左移p位（超过尽头接到后面）
//最优解原理：左侧p个元素逆置，后面n-p个元素也逆置，然后整个数组逆置
//时间复杂度：O(n) 空间复杂度：O(1)
void p18q10(SqList L, int p) {
    for (int i = 0; i < p / 2; i++)
        swap(L.data, i, p - 1 - i);
    printArr(L.data, L.length);
    for (int i = p; i < p + (L.length - p) / 2; i++)
        swap(L.data, i, p + L.length - 1 - i);
    printArr(L.data, L.length);
    for (int i = 0; i < L.length / 2; i++)
        swap(L.data, i, L.length - 1 - i);
    printArr(L.data, L.length);
}

void p18q11(SqList A, SqList B, SqList C) {
    bubbleSort(A.data, A.length);
    bubbleSort(B.data, B.length);

    p18q7(A, B, C);
    printf("%d", C.data[C.length / 2]);
}

int p18q12(SqList L){

}