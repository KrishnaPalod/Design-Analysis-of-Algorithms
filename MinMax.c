#include <stdio.h>
#include <limits.h>

struct MinMax {
    float min;
    float max;
};

struct MinMax findMaxMin(double arr[], int low, int high) {
    struct MinMax result, left, right;
    int mid;

    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    mid = (low + high) / 2;
    left = findMaxMin(arr, low, mid);
    right = findMaxMin(arr, mid + 1, high);

    // Compare and update min and max accordingly
    if (left.min < right.min)
        result.min = left.min;
    else
        result.min = right.min;

    if (left.max > right.max)
        result.max = left.max;
    else
        result.max = right.max;

    return result;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    double a[n];
    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    printf("Entered numbers are:\n");
    for (int i = 0; i < n; i++) {
        printf("%g ", a[i]);
    }
    printf("\n");

    struct MinMax result = findMaxMin(a, 0, n - 1);
    printf("Maximum value: %g\n", result.max);
    printf("Minimum value: %g\n", result.min);

    return 0;
}
