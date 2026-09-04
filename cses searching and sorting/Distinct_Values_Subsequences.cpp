#include <iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;


int main() {
    int n;
    cin >> n;

    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    ll ans = 1;

    for (auto [x, f] : freq) {
        ans = ans * (f + 1) % MOD;
    }

    cout << (ans - 1 + MOD) % MOD << '\n';
}