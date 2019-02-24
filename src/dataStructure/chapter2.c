//线性表
//静态分配
#define MaxSize 50
//typedef：为一种数据类型定义一个新名字 以后使用SqList的时候就可以省略struct关键字了
typedef struct {
    int data[MaxSize];
    int length;
} SqList;

//插入
bool ListInsert(SqList L, int i, int e) {
    if (i < 1 || i > L.length + 1) return false;
    if (L.length > MaxSize) return false;
    for (int j = L.length - 1; j >= i; j--)
        L.data[j + 1] = L.data[j];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

//删除
bool ListDelete(SqList L, int i, int e) {
    if (i < 1 || i > L.length) return false;
    e = L.data[i - 1];
    //把第i个元素后面所有的元素赋值给前一个元素
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
}

//按值查找
int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e) return i + 1;
    return 0;
}

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
            L.data[k] == L.data[i];
            k++;
        }
    L.length == k;
}

bool p18q4(SqList L, int s, int t) {
    if (s >= t || L.length == 0) return false;
    bubbleSort(L.data, L.length);
    for (int i = s - 1; i < t; i++)
        L.data[i] = L.data[t + (s - 1 - i)];
    L.length -= t - s;
    printArr(L.data, L.length);
}