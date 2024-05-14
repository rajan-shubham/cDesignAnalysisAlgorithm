//Quick sort alogorithm in c

#include <stdio.h>

void interch(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void Quick_sort(float a[], int m, int n) {
    if (m < n) {
        int i = m;
        int j = n + 1;
        float key = a[m];
        while (1) {
            do {
                i++;
            } while (a[i] < key);
            do {
                j--;
            } while (a[j] > key);
            if (i < j) {
                interch(&a[i], &a[j]);
            } else {
                break;
            }
        }
        interch(&a[m], &a[j]);
        Quick_sort(a, m, j - 1);
        Quick_sort(a, j + 1, n);
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

    Quick_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}
