#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

int static1(int arr[NMAX][NMAX], int rows, int cols);
int dynamic1(int **arr, int rows, int cols);
int dynamic2(int **arr, int rows, int cols);
int dynamic3(int **arr, int rows, int cols);
void free_matrix(int **matrix, int rows);

int main() {
    int arr[NMAX][NMAX];
    int **dynamic_arr = NULL;
    int rows, cols, choice;

    if ((scanf("%d", &choice) != 1) || choice <= 0 || choice > 4) {
        printf("n/a");
        return -1;
    }
    if ((scanf("%d%d", &rows, &cols) != 2) || rows <= 0 || cols <= 0) {
        printf("n/a");
        return 1;
    }

    switch (choice) {
        case 1:
            if (static1(arr, rows, cols) != 0) {
                printf("n/a");
                return 1;
            }
            break;
        case 2:
            dynamic_arr = (int **)malloc(rows * sizeof(int *));
            for (int i = 0; i < rows; i++) {
                dynamic_arr[i] = (int *)malloc(cols * sizeof(int));
            }
            if (dynamic1(dynamic_arr, rows, cols) != 0) {
                free_matrix(dynamic_arr, rows);
                printf("n/a");
                return 1;
            }
            break;
        case 3:
            dynamic_arr = (int **)malloc(rows * sizeof(int *));
            int *data = (int *)malloc(rows * cols * sizeof(int));
            for (int i = 0; i < rows; i++) {
                dynamic_arr[i] = data + i * cols;
            }
            if (dynamic2(dynamic_arr, rows, cols) != 0) {
                free_matrix(dynamic_arr, rows);
                printf("n/a");
                return 1;
            }
            free(data);
            break;
        case 4:
            dynamic_arr = (int **)malloc(rows * sizeof(int *) + rows * cols * sizeof(int));
            int *data1 = (int *)(dynamic_arr + rows);
            for (int i = 0; i < rows; i++) {
                dynamic_arr[i] = data1 + i * cols;
            }
            if (dynamic3(dynamic_arr, rows, cols) != 0) {
                free_matrix(dynamic_arr, rows);
                printf("n/a");
                return 1;
            }
            free(data1);
            break;
    }

    free_matrix(dynamic_arr, rows);
    return 0;
}

int static1(int arr[NMAX][NMAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &arr[i][j]) != 1) {
                return -1;
            }
        }
    }
    if (getchar() != '\n') return -1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", arr[i][j]);
            if (j < cols - 1) printf(" ");
        }
        if (i < rows - 1) printf("\n");
    }
    return 0;
}

int dynamic1(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &arr[i][j]) != 1) {
                return -1;
            }
        }
    }
    if (getchar() != '\n') return -1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", arr[i][j]);
            if (j < cols - 1) printf(" ");
        }
        if (i < rows - 1) printf("\n");
    }
    return 0;
}

int dynamic2(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &arr[i][j]) != 1) {
                return -1;
            }
        }
    }
    if (getchar() != '\n') return -1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", arr[i][j]);
            if (j < cols - 1) printf(" ");
        }
        if (i < rows - 1) printf("\n");
    }
    return 0;
}

int dynamic3(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &arr[i][j]) != 1) {
                return -1;
            }
        }
    }
    if (getchar() != '\n') return -1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", arr[i][j]);
            if (j < cols - 1) printf(" ");
        }
        if (i < rows - 1) printf("\n");
    }
    return 0;
}

void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}