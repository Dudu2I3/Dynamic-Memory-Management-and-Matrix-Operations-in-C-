#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, int n, int m);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);
int transpose(int **matrix, int n, int m, int **matrix_result, int *n_result, int *m_result);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);
void free_matrix(int **matrix, int rows);

int main() {
    int **dynamic_arr1 = NULL;
    int **dynamic_arr2 = NULL;
    int **dynamic_arr3 = NULL;
    int rows1, cols1, rows2, cols2, rows3, cols3, choice;

    if ((scanf("%d", &choice) != 1) || choice <= 0 || choice > 3) {
        printf("n/a");
        return -1;
    }
    if ((scanf("%d%d", &rows1, &cols1) != 2) || rows1 <= 0 || cols1 <= 0) {
        printf("n/a");
        return 1;
    }
    dynamic_arr1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        dynamic_arr1[i] = (int *)malloc(cols1 * sizeof(int));
    }
    if (input(dynamic_arr1, rows1, cols1) != 0) {
        free_matrix(dynamic_arr1, rows1);
        printf("n/a");
        return 1;
    }

    if (choice == 1 || choice == 3) {
        if ((scanf("%d%d", &rows2, &cols2) != 2) || rows2 <= 0 || cols2 <= 0) {
            printf("n/a");
            return 1;
        }
        dynamic_arr2 = (int **)malloc(rows2 * sizeof(int *));
        for (int i = 0; i < rows2; i++) {
            dynamic_arr2[i] = (int *)malloc(cols2 * sizeof(int));
        }
        if (input(dynamic_arr2, rows2, cols2) != 0) {
            free_matrix(dynamic_arr2, rows2);
            printf("n/a");
            return 1;
        }
    }

    switch (choice) {
        case 1:
            dynamic_arr3 = (int **)malloc(rows1 * sizeof(int *));
            for (int i = 0; i < rows1; i++) {
                dynamic_arr3[i] = (int *)malloc(cols1 * sizeof(int));
            }
            if (sum(dynamic_arr1, rows1, cols1, dynamic_arr2, rows2, cols2, dynamic_arr3, &rows3, &cols3) !=
                0) {
                printf("n/a");
                return 1;
            }
            output(dynamic_arr3, rows3, cols3);
            free_matrix(dynamic_arr3, rows3);
            break;
        case 2:
            dynamic_arr3 = (int **)malloc(cols1 * sizeof(int *));
            for (int i = 0; i < cols1; i++) {
                dynamic_arr3[i] = (int *)malloc(rows1 * sizeof(int));
            }
            if (transpose(dynamic_arr1, rows1, cols1, dynamic_arr3, &rows3, &cols3) != 0) {
                printf("n/a");
                return 1;
            }
            output(dynamic_arr3, rows3, cols3);
            free_matrix(dynamic_arr3, rows3);
            break;
        case 3:
            dynamic_arr3 = (int **)malloc(rows1 * sizeof(int *));
            for (int i = 0; i < rows1; i++) {
                dynamic_arr3[i] = (int *)malloc(cols2 * sizeof(int));
            }
            if (mul(dynamic_arr1, rows1, cols1, dynamic_arr2, rows2, cols2, dynamic_arr3, &rows3, &cols3) !=
                0) {
                printf("n/a");
                return 1;
            }
            output(dynamic_arr3, rows3, cols3);
            free_matrix(dynamic_arr3, rows3);
            break;
    }

    free_matrix(dynamic_arr1, rows1);
    if (dynamic_arr2) free_matrix(dynamic_arr2, rows2);

    return 0;
}

int input(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return -1;
            }
        }
    }
    if (getchar() != '\n') return -1;
    return 0;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j < m - 1) printf(" ");
        }
        if (i < n - 1) printf("\n");
    }
}
void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result) {
    if (n_first == n_second && m_first == m_second) {
        *n_result = n_first;
        *m_result = m_first;
        for (int i = 0; i < n_first; i++) {
            for (int j = 0; j < m_first; j++) {
                matrix_result[i][j] = matrix_first[i][j] + matrix_second[i][j];
            }
        }
        return 0;
    }
    return -1;
}

int transpose(int **matrix, int n, int m, int **matrix_result, int *n_result, int *m_result) {
    *n_result = m;
    *m_result = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix_result[j][i] = matrix[i][j];
        }
    }
    return 0;
}

int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result) {
    if (m_first != n_second) {
        return -1;
    }
    *n_result = n_first;
    *m_result = m_second;
    for (int i = 0; i < n_first; i++) {
        for (int j = 0; j < m_second; j++) {
            matrix_result[i][j] = 0;
            for (int k = 0; k < m_first; k++) {
                matrix_result[i][j] += matrix_first[i][k] * matrix_second[k][j];
            }
        }
    }
    return 0;
}