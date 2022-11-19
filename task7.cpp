#include <iostream>

#define N 8

using namespace std;

int matrica[N][N] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
};

int get_zero_counter_in_row (int row) {
    int a = row;
    int b = N - row - 1;

    if (a > b) {
        int c = a;
        a = b;
        b = c;
    }

    int counter = 0;

    for (int i = a; i <= b; i++) {
        if (matrica[row][i] == 0) {
            counter++;
        }
    }

    return counter;
}

void print_matrix () {
    for (int y = 0; y < N; y++) {
        int a = y;
        int b = N - y - 1;

        if (a > b) {
            int c = a;
            a = b;
            b = c;
        }

        for (int x = 0; x < N; x++) {
            if (a <= x && x <= b) {
                printf("\x1B[32m%4d\033[0m\t", matrica[y][x]);
            } else {
                printf("%4d\t", matrica[y][x]);
            }
        }

        printf("\n");
    }
}

// int get_zero_counter_in_number (int);

int main () {
    print_matrix();

    for (int i = 0; i < N; i++) {
        int counter = get_zero_counter_in_row(i);
        cout << "get_zero_counter_in_row(" << i << ") = " << counter << endl;
    }

    // cout << "123000123 " << get_zero_counter_in_number(123000123) << endl;
}

// int get_zero_counter_in_number (int number) {
//     int counter = 0;

//     while (number > 0) {
//         int digit = number % 10;
//         number = number / 10;
//         counter += digit == 0;
//     }

//     return counter;
// }