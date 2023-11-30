#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bubble sort
void bubbleSort(int arr[], int n) {
	int i;
    for (i = 0; i < n - 1; i++) {
    	int j;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Selection sort
void selectionSort(int arr[], int n) {
	int i;
    for (i = 0; i < n - 1; i++) {
        int minIndex = i;
        int j;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    srand(time(0)); 
    
    int n = 10; 
    int arr[n]; 

    int i;
	for (i = 0; i < n; i++) {
        arr[i] = rand() % 100; 
    }

    printf("Unsorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);
    printf("Array sorted using bubble sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100; 
    }

    printf("Unsorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n);
    printf("Array sorted using selection sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
