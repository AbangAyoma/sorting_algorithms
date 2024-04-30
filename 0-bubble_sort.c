#include<stdio.h>
#include "sort.h"
#include<stdlib.h>

void bubble_sort(int *array, size_t size);
void swap(int *a, int *b);

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    bubble_sort(array, size);

    printf("Sorted array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *array, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        // Flag to check if any swap occurred in this iteration
        int swapped = 0;
        
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }

        // If no two elements were swapped in the inner loop, then the array is already sorted
        if (!swapped)
            break;

        // Print the array after each pass
        printf("Array after pass %zu: ", i + 1);
        for (size_t k = 0; k < size; k++) {
            printf("%d ", array[k]);
        }
        printf("\n");
    }
}
