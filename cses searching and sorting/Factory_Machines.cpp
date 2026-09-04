#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    int n;
    ll t;
    cin >> n >> t;

    vector<ll> k(n);

    for (auto &x : k)
        cin >> x;

    ll lo = 0;
    ll hi = 1e18;

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;

        ll products = 0;

        for (ll x : k) {
            products += mid / x;

            if (products >= t)
                break;
        }

        if (products >= t)
            hi = mid;
        else
            lo = mid + 1;
    }

    cout << lo << '\n';
}