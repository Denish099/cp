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

    for (int k = 1; k <= n; k++) {
        ll total = 1LL * k * k * (1LL * k * k - 1) / 2;
        ll attacking = 4LL * (k - 1) * (k - 2);

        cout << total - attacking << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}