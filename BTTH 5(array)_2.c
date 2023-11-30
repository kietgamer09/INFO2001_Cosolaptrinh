#include <stdio.h>


int linearSearch(int arr[], int n, int x) {
	int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1; 
}


int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid; 
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int arr[] = {2, 5, 9, 12, 15, 21, 25, 30, 35, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 21; 


    int linearIndex = linearSearch(arr, n, x);
    if (linearIndex != -1) {
        printf("Phan tu %d duoc tim thay tai chi so %d\n", x, linearIndex);
    } else {
        printf("Phan tu %d khong duoc tim thay\n", x);
    }


    int binaryIndex = binarySearch(arr, 0, n - 1, x);
    if (binaryIndex != -1) {
        printf("Phan tu %d duoc tim thay tai chi so %d\n", x, binaryIndex);
    } else {
        printf("Phan tu %d khong duoc tim thay\n", x);
    }

    return 0;
}
