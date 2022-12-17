#include <iostream>
#include <ctime> 

using namespace std;

int N = 0;
int M = 0;
float** matrix;

void fun (float& min, float& max) {
    max = matrix[0][M/2];

    for (int y = 0; y < N / 2; y++) {
        for (int x = M / 2; x < M; x++) {
            if (matrix[y][x] > max) {
                max = matrix[y][x];
            }
        }
    }

    min = matrix[N/2][0];
    for (int y = N / 2; y < N; y++) {
        for (int x = 0; x < M / 2; x++) {
            if (matrix[y][x] < min) {
                min = matrix[y][x];
            }
        }
    }
}

int main () {
    srand((unsigned)time(0)); 

    cin >> N;
    cin >> M;

    matrix = new float*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new float[M];

        for (int j = 0; j < M; j++) {
            matrix[i][j] = float(5000 -(rand() % 10000))/100.;
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cout << matrix[y][x] << "\t";
        }
        cout << endl;
    }

    float min;
    float max;

    fun(min, max);

    cout << min << " " << max << endl;
}