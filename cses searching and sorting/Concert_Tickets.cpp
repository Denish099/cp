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
    ll n, m;
    cin >> n >> m;

    multiset<ll> tickets;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        tickets.insert(x);
    }

    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;

        auto it = tickets.upper_bound(x);

        if (it == tickets.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            --it;
            cout << *it << endl;
            tickets.erase(it);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}