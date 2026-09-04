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

void solve()
{
    ll Q, V;
    cin >> Q >> V;

    priority_queue<ll> pq;

    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            ll t, w;
            cin >> t >> w;

            pq.push(w - t);
        }
        else {
            ll t;
            cin >> t;

            if (pq.empty()) {
                cout << -1 << endl;
                continue;
            }

            ll x = pq.top();
            pq.pop();

            ll charge = min(V, x + t);

            cout << charge << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}