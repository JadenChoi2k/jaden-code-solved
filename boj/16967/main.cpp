#include <iostream>
using namespace std;

int H, W, X, Y;
int A[300][300];
int B[600][600];

void printA() {
    // print
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (j == W - 1) {
                cout << A[i][j] << endl;
            } else {
                cout << A[i][j] << " ";
            }
        }
    }
}

int main() {
    cin.tie(0); cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> H >> W >> X >> Y;

    for (int i = 0; i < H + X; i++) {
        for (int j = 0; j < W + Y; j++) {
            cin >> B[i][j];
        }
    }

    // non-overlapping area (upper-left)
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i < X || j < Y) {
                A[i][j] = B[i][j];
            }
        }
    }

    // non-overlapping area (bottom-right)
    for (int i = X; i < X + H; i++) {
        for (int j = Y; j < Y + W; j++) {
            if (i >= H || j >= W) {
                A[i-X][j-Y] = B[i][j];
            }
        }
    }

    // find A[i][j]
    // B[i][j] = A[i][j] + A[i-X][j-Y]
    for (int i = X; i < H - X; i++) {
        for (int j = Y; j < W - Y; j++) {
            A[i][j] = B[i][j] - A[i-X][j-Y];
        }
    }

    printA();
}