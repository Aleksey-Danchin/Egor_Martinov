#include <iostream>

using namespace std;

int main () {
    float x;
    cout << "x = ";
    cin >> x;

    if (x == 0) {
        cout << "Error: X equal 0." << endl;
        return 0;
    }

    int m;
    cout << "m = ";
    cin >> m;

    if (m < 0) {
        cout << "Error: m less 0." << endl;
        return 0;
    }

    float s = 0;

    for (float i = 1; i <= m; i++) {
        s += (i * x - 10.) / x;
    }

    cout << "s = " << s << endl;
}