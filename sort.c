#include <stdio.h>
#include <stdlib.h>

int input(int *a, int *n);
int sort(int *a, int n);
void output(int *a, int n);

int main() {
    int *arr;
    int n;
    if (scanf("%d", &n) != 1) {
        printf("n/a");
        return -1;
    }
    if (n == 0) {
        printf("n/a");
        return -1;
    }
    arr = (int *)malloc(n * sizeof(int));
    if (input(arr, &n) != 0) {
        free(arr);
        printf("n/a");
        return 1;
    }
    sort(arr, n);
    output(arr, n);
    free(arr);
    return 0;
}

int input(int *a, int *n) {
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) return -1;
    }
    return 0;
}

int sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
}
