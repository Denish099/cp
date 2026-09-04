#include <iostream>
using namespace std;

using ll = long long;

ll solve(ll x, ll y) {
    ll n = max(x, y);
    ll sq = n * n;

    if (n % 2 == 0) {
        if (x == n)
            return sq - y + 1;
        else
        
            return (n - 1) * (n - 1) + x;
    }
    else {
        
        if (y == n)
            return sq - x + 1;
        else
            return (n - 1) * (n - 1) + y;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll x, y;
        cin >> x >> y;

        cout << solve(x, y) << '\n';
    }
}