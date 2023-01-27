#include <iostream>
using namespace std;

const int N = 1005;
int matrix[N][N];
int n, m;

void rotate() {
    for (int layer = 0; layer < min(n, m) / 2; layer++) {
        int first = layer;
        int last = min(n, m) - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top = matrix[first][i];

            matrix[first][i] = matrix[last-offset][first];
            matrix[last-offset][first] = matrix[last][last-offset];
            matrix[last][last-offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    rotate();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}