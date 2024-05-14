#include <stdio.h>

void interch(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(float A[], int i, int heap_size) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest;

    if (l <= heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r <= heap_size && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        interch(&A[i], &A[largest]);
        maxHeapify(A, largest, heap_size);
    }
}

void buildMaxHeap(float A[], int length) {
    int heap_size = length - 1;
    for (int i = length / 2; i >= 0; i--) {
        maxHeapify(A, i, heap_size);
    }
}

void Heap_Sort(float A[], int length) {
    int heap_size = length - 1;
    buildMaxHeap(A, length);
    for (int i = length - 1; i >= 1; i--) {
        interch(&A[0], &A[i]);
        heap_size--;
        maxHeapify(A, 0, heap_size);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    float arr[n];
    printf("Enter Array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    Heap_Sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}
