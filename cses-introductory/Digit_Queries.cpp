#include <iostream>
#include <string>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        ll k;
        cin >> k;

        ll digits = 1;
        ll count = 9;
        ll start = 1;

        while (k > digits * count) {
            k -= digits * count;

            digits++;
            count *= 10;
            start *= 10;
        }

        ll number = start + (k - 1) / digits;

        ll index = (k - 1) % digits;

        string s = to_string(number);

        cout << s[index] << '\n';
    }

    return 0;
}