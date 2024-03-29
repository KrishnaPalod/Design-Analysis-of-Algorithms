#include <stdio.h>

#include <stdlib.h>


// Function to allocate memory for a matrix

int** allocateMatrix(int rows, int cols) {

    int **matrix = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++)

        matrix[i] = (int *)malloc(cols * sizeof(int));

    return matrix;

}


// Function to free memory allocated for a matrix

void freeMatrix(int **matrix, int rows) {

    for (int i = 0; i < rows; i++)

        free(matrix[i]);

    free(matrix);

}


// Function to print a matrix

void printMatrix(int **matrix, int rows, int cols) {

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++)

            printf("%d ", matrix[i][j]);

        printf("\n");

    }

}


// Function to perform matrix multiplication using Stassen algorithm

int** stassenMultiply(int **A, int **B, int n) {

    // Perform Stassen matrix multiplication here

    // This is a placeholder for the actual implementation

    // You can replace it with the actual Stassen algorithm

    

    // Allocate memory for the result matrix

    int **result = allocateMatrix(n, n);


    // Dummy multiplication for demonstration

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            result[i][j] = 0;

            for (int k = 0; k < n; k++)

                result[i][j] += A[i][k] * B[k][j];

        }

    }


    return result;

}


int main() {

    int n;

    printf("Enter the size of matrices: ");

    scanf("%d", &n);


    // Allocate memory for matrices A and B

    int **A = allocateMatrix(n, n);

    int **B = allocateMatrix(n, n);


    // Read matrices A and B from user input

    printf("Enter elements of matrix A:\n");

    for (int i = 0; i < n; i++)

        for (int j = 0; j < n; j++)

            scanf("%d", &A[i][j]);


    printf("Enter elements of matrix B:\n");

    for (int i = 0; i < n; i++)

        for (int j = 0; j < n; j++)

            scanf("%d", &B[i][j]);


    // Perform Stassen matrix multiplication

    int **result = stassenMultiply(A, B, n);


    // Print the result

    printf("Result of matrix multiplication:\n");

    printMatrix(result, n, n);


    // Free allocated memory

    freeMatrix(A, n);

    freeMatrix(B, n);

    freeMatrix(result, n);


    return 0;

}