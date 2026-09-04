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

struct DSU
{
    int componenets;
    int n;
    vector<int> parent;
    vector<int> size;

    DSU(int n)
    {
        n = n;
        componenets = n;
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        else
            return parent[x] = find(x);
    }

    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        componenets--;

        return true;
    }

    int getsize(int x)
    {
        return size[find(x)];
    }
};
vector<vector<int>> adj;
void solve()
{
    int n;
    cin >> n;
    adj.resize(n);

    for (int u = 2; u <= n; u++)
    {
        int v;
        cin >> v;

        adj[v].push_back(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}