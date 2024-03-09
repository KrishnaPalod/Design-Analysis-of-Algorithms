#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    float arr[n],key;
    printf("\nCAUTION : please don't enter a decimal number more than 5 decimal values");
    printf("\nEnter elements of array : ", n); 
    for (i = 0; i < n; i++){
        scanf("%f", &arr[i]);
    }
    printf("\nelemets of  array are : ");
    for (i = 0; i < n; i++){
        printf("%g ", arr[i]);
    }
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    printf("\nelemantes after sorting are : ");
    for (i = 0; i < n; i++){
        printf("%g ", arr[i]);
    }
    printf("\n");

    return 0;
}
