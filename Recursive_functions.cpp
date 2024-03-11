#include <iostream>
using namespace std;

int f(int x) {
    if (x == 0) {
        return 0;
    }
    else if (x % 2 == 0) {
        return f(x / 2);
    }
    else {
        return 1 + f(x - 1);
    }
}

int main() {

    // a)
    cout << "f(1) = " << f(1) << endl;
    // b)
    cout << "f(2) = " << f(2) << endl;
    // c)
    cout << "f(3) = " << f(3) << endl;
    // d)
    cout << "f(99) = " << f(99) << endl;
    // e)
    cout << "f(100) = " << f(100) << endl;
    // f)
    cout << "f(128) = " << f(128) << endl;


    return 0;
}