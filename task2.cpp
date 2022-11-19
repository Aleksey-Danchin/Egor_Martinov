#include <iostream>

using namespace std;

int main () {
    int a = 0;

    cout << "a = ";
    cin >> a;

    int c1, c2, c3;
    c3 = a % 10;
    c2 = (a / 10) % 10;
    c1 = a / 100;

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3 << endl;

    if (c1 < c2 && c2 < c3) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    cout << endl;
}