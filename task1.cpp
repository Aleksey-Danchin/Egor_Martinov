#include <iostream>

using namespace std;

int main () {
    int a, b;

    cout << "b = ";

    while (true) {
        cin >> b;

        if (b == 0) {
            cout << "b cann't be 0" << endl;
        } else {
            break;
        }
    }

    cout << "a = ";
    cin >> a;

    float x = float(1 + a) / float(b);

    cout << x;

    cout << endl;
}

// scanf printf
// cin cout