void printArr(int arr[], int len) {
    printf("\narray:\n");
    for (int i = 0; i < len; i++)
        printf("%d\t", arr[i]);
}

void swap(int arr[], int index1, int index2) {
    arr[index1] += arr[index2];
    arr[index2] = arr[index1] - arr[index2];
    arr[index1] -= arr[index2];
}

//冒泡排序
void bubbleSort(int arr[], int len) {
    for (int j = 0; j < len - 1; j++)
        for (int i = 0; i < len - 1 - j; i++)
            if (arr[i] > arr[i + 1])  //不借助第三方变量的两个值交换
                swap(arr, i, i + 1);
    printArr(arr, len);
}

//插入排序
/*void insertionSort(int arr[]) {
    int sortedArr[] = {arr[0]};
    for (int i = 1; i < sizeof(&arr); i++)
        for (int j = sizeof(&sortedArr) - 1; j >= 0; j--)
            if (arr[i] > sortedArr[j]);
}*/

//选择排序
void selectionSort(int arr[], int len) {
    for (int i = 0, indexMin; i < len - 1; i++) {
        indexMin = i;
        for (int j = i; j < len; j++)
            if (arr[j] < arr[indexMin])
                indexMin = j;
        if (i != indexMin)
            swap(arr, i, indexMin);
    }
    printArr(arr, len);
}

