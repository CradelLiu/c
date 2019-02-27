//折半查找(有序顺序表)
int binarySearch(int arr[], int len, int target) {
    bubbleSort(arr, len);

    int low = 0, mid, high = len - 1;
    while (low <= high) {
        mid = (low + high) / 2; //自动向下取整
        if (target > arr[mid])
            low = mid + 1;
        else if (target < arr[mid])
            high = mid - 1;
        else {
            printf("\nindex of %d is %d", target, mid);
            return mid;
        }
    }
    return -1;
}