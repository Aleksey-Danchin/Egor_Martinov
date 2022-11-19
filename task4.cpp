#include <iostream>

using namespace std;

// int main () {
//     int x[12] = {6, 7, 3, 1, 0, 9, 1, 2, 5, 8, 1, 8};

//     int mi = 0;
//     for (int i = 1; i < 12; i++) {
//         if (x[i] > x[mi]) {
//             mi = i;
//         }
//     }

//     int s = 0;
//     for (int i = mi + 1; i < 12; i++) {
//         s += x[i];
//     }

//     cout << s << endl;
// }

int main () {
    int x[12] = {6, 7, 3, 1, 0, 9, 1, 2, 5, 8, 1, 8};

    int mi = 0;
    int s = 0;
    for (int i = 1; i < 12; i++) {
        if (x[i] > x[mi]) {
            mi = i;
            s = 0;
        } else {
            s += x[i];
        }
    }


    cout << s << endl;
}