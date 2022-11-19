#include <iostream>

#define N1 10
#define N2 15

using namespace std;

int get_first_negative_item_index(int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            return i;
        }
    }

    return -1;
};

int main () {
    int a[N1] = {0, 1, 2, 3, 4, 5, 6, -7, 8, 9};
    int b[N2] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, 12, 13, 14};

    int ai = get_first_negative_item_index(a, N1);
    int bi = get_first_negative_item_index(b, N2);

    float as = 0.;
    for (int i = ai + 1; i < N1; i++) {
        as += float(a[i]) / float((N1 - ai - 1));
    }

    float bs = 0.;
    for (int i = bi + 1; i < N2; i++) {
        bs += float(b[i]) / float((N2 - bi - 1));
    }

    cout << "as = " << as << endl;
    cout << "bs = " << bs << endl;
}