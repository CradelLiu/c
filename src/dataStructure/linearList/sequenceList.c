//数组的静态分配
#define MaxSize 50
typedef struct { //typedef：为一种数据类型定义一个新名字 以后使用SqList的时候就可以省略struct关键字了
    int data[MaxSize];
    int length;
} SqList;

//数组的动态分配
typedef struct {
    int *data;
    int length;
} SqListDynamic;

//动态分配语句
//L.data = (ElemType *) malloc(sizeof(ElemType) * initSize);

/**
 * 插入
 *   时间复杂度
 *     最好
 *       插在最后
 *       O(1)
 *     平均
 *       插入位置有n+1个
 *       每个位置插入的概率为1/(n+1)
 *       每个插入位置的循环次数为(n-i+1)
 *       所以平均循环次数为每次的概率和每次的次数相乘并求和
 *       最后得到O(n)
 *     最坏
 *       插在最前
 *       要移动n个元素
 *       O(n)
 */
bool insert(SqList L, int i, int e) {
    if (i < 1 || i > L.length + 1) return false;
    if (L.length > MaxSize) return false;
    for (int j = L.length - 1; j >= i; j--)
        L.data[j + 1] = L.data[j];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

/**
 * 删除
 *   时间复杂度
 *     最好
 *       删除最后的元素
 *       O(1)
 *     平均
 *       可以删除的元素有n个
 *       每个元素被删除的概率为1/n
 *       每个元素被删除时，要移动的元素个数为(n-i)
 *       所以平均循环次数为每次的概率和每次的次数相乘并求和
 *       最后得到O(n)
 *     最坏
 *       删除最前面的元素
 *       要移动n-1个元素
 *       O(n)
 */
bool delete(SqList L, int i, int e) {
    if (i < 1 || i > L.length) return false;
    e = L.data[i - 1];
    //把第i个元素后面所有的元素赋值给前一个元素
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
}

/**
 * 按值查找
 *   时间复杂度
 *     最好
 *       第一个就找到
 *       O(1)
 *     平均
 *       待搜索的元素有n个
 *       每个元素是目标元素的概率为1/n
 *       每个元素被搜索到时，要搜索的元素个数为i
 *       所以平均循环次数为每次的概率和每次的次数相乘并求和
 *       最后得到O(n)
 *     最坏
 *       最后一个才找到
 *       要搜索n个元素
 *       O(n)
 */
int locate(SqList L, int e) {
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e) return i + 1;
    return 0;
}