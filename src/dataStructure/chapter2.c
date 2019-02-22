//线性表
//静态分配
#define MaxSize 50
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

//插入
bool ListInsert(SqList &L, int i,ElemType e) {
    if(i<1||i>L.length+1)return false;

}