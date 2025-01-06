#include <stdio.h>

int binarySearch(int arr[], int arrSize, int searchValue) {
    int low = 0;
    int high = arrSize - 1;
    int mid = arr[arrSize / 2];
    if (searchValue == mid) {
        return mid;
    }
    arrSize = arrSize / 2;
    if (searchValue < mid) {
        high = arrSize - 1;
    } else {
        low = arrSize + 1;
    }
    return binarySearch(arr, arrSize, searchValue);    
}

int main() {
    
    int arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = i;
    }
    int searchValue = 50;
    printf("%d",binarySearch(arr, 100, 3));
    

    return 0;
}