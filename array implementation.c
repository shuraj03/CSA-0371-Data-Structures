#include <stdio.h>

#define MAX_SIZE 100

int insertElement(int arr[], int size, int pos, int value) {
    if (size >= MAX_SIZE || pos < 0 || pos > size) {
        return -1; 
    }

    for (int i = size - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos] = value;
    return size + 1; 
}

int deleteElement(int arr[], int size, int pos) {
    if (size <= 0 || pos < 0 || pos >= size) {
        return -1; 
    }

    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1; 
}

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;


    size = insertElement(arr, size, 0, 5);
    size = insertElement(arr, size, 1, 10);
    size = insertElement(arr, size, 1, 7);


    displayArray(arr, size);

    size = deleteElement(arr, size, 1);

    displayArray(arr, size);
    
    return 0;
    
}