#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt0 = 0;

    for (char c : s) {
        if (c == '0') {
            cnt0++;
        }
    }

    if (cnt0 % 2 == 1 && cnt0 > 1) {
        cout << "ALICE\n";
    } else {
        cout << "BOB\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}