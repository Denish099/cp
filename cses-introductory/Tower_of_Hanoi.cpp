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


void solve(int n, int from, int to, int aux) {
    if (n == 0) return;

    solve(n - 1, from, aux, to);

    cout << from << " " << to << '\n';

    solve(n - 1, aux, to, from);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << (1LL << n) - 1 << '\n';

    solve(n, 1, 3, 2);

    return 0;
}