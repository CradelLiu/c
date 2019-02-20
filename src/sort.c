#include <stdio.h>
#include "math.h"

void printArr(int arr[]) {
    for (int i = 0; i < sizeof(arr) - 1; i++)
        printf("%d\t", arr[i]);
}

//冒泡排序
void bubbleSort(int arr[]) {
    for (int j = 0; j < sizeof(arr) - 1; j++)
        for (int i = 0; i < sizeof(arr) - 1 - j; i++)
            if (arr[i] > arr[i + 1]) { //不借助第三方变量的两个值交换
                arr[i] += arr[i + 1];
                arr[i + 1] = arr[i] - arr[i + 1];
                arr[i] = arr[i] - arr[i + 1];
            }
    printArr(arr);
}

//插入排序
void insertionSort(int arr[]) {
    int sortedArr[] = {arr[0]};
    for (int i = 1; i < sizeof(arr); i++)
        for (int j = sizeof(sortedArr) - 1; j >= 0; j--)
            if (arr[i] > sortedArr[j])
}

//选择排序

