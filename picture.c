#include <stdio.h>
#include <stdlib.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform((int *)picture_data, picture, N, M);

    make_picture(picture, N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", picture[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};

    reset_picture(picture, n, m);
    // tree trunk
    for (int i = 0; i < 4; i++) {
        picture[10][2 + i] = tree_trunk[i];
        picture[5 + i][3] = tree_trunk[i];
        picture[5 + i][4] = tree_trunk[i];
        if (i == 3) {
            picture[9][3] = tree_trunk[0];
            picture[9][4] = tree_trunk[0];
        }
    }
    // tree_foliage
    for (int i = 0; i < 4; i++) {
        picture[2 + i][3] = tree_foliage[i];
        picture[2 + i][4] = tree_foliage[i];
        picture[3][2 + i] = tree_foliage[i];
        picture[4][2 + i] = tree_foliage[i];
    }
    // sun
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            picture[i + 1][j + 7] = sun_data[i][j];
        }
    }
    // frame
    for (int i = 0; i < m; i++) {
        picture[0][i] = frame_w[i];
        picture[7][i] = frame_w[i];
        picture[n - 1][i] = frame_w[i];
    }
    for (int i = 0; i < n; i++) {
        picture[i][0] = frame_h[i];
        picture[i][6] = frame_h[i];
        picture[i][m - 1] = frame_h[i];
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}
