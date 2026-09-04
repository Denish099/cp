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

    long long sum = 1LL * n * (n + 1) / 2;

    if (sum % 2 != 0) {
        cout << "NO\n";
        return;
    }

    long long target = sum / 2;

    vector<int> a, b;

    for (int i = n; i >= 1; i--) {
        if (i <= target) {
            a.push_back(i);
            target -= i;
        } else {
            b.push_back(i);
        }
    }

    cout << "YES\n";

    cout << a.size() << '\n';
    for (int x : a)
        cout << x << ' ';
    cout << '\n';

    cout << b.size() << '\n';
    for (int x : b)
        cout << x << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();


    return 0;
}