#include <iostream>
#include <stack>

using namespace std;

bool is_prime(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

stack<int> prime_divisors(int luku) {
    stack<int> divisors;

    for (int i = 2; i <= luku; ++i) {
        if (is_prime(i) && (luku % i == 0)) {
            divisors.push(i);
            while (luku % i == 0) {
                luku /= i;
            }
        }
    }

    return divisors;
}


int main() {
    int luku;

    cout << "Enter an integer: ";
    cin >> luku;

    stack<int> divisors = prime_divisors(luku);

    cout << "Prime divisors in descending order: ";
    while (!divisors.empty()) {
        cout << divisors.top() << " ";
        divisors.pop();
    }

    cout << endl;

    return 0;
}
