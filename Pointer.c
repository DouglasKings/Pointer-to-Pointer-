#include <stdio.h>
#include <stdlib.h>

// Function prototype for creating a dynamic 2D array
int** createDynamic2DArray(int rows, int cols);

int main() {
    // Define the size of the 2D array
    int rows = 3;
    int cols = 4;

    // Create and initialize the 2D array
    int** arr = createDynamic2DArray(rows, cols);

    // Print the elements of the 2D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(arr[i] + j));
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

// Function to create a dynamic 2D array
int** createDynamic2DArray(int rows, int cols) {
    // Allocate memory for the rows
    int** arr = (int**) malloc(rows * sizeof(int*));

    // Allocate memory for each row and initialize
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * cols + j; // Example initialization
        }
    }

    // Return the pointer to the 2D array
    return arr;
}
