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
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> vis(n, 0);
    vector<vector<int>> ans;

    auto dfs = [&](auto &&self, int node) -> void
    {
        vis[node] = 1;

        for (int i = 0; i < n; i++)
        {
            if (i == node)
            {
                continue;
            }

          
            if (arr[i] != arr[node] && !vis[i])
            {
         
                ans.push_back({node + 1, i + 1});

             
                self(self, i);
            }
        }
    };

    dfs(dfs, 0);

    if (ans.size() != n - 1)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << "\n";
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