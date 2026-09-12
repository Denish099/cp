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
    ll n, s, L;
    cin >> n >> s >> L;
    --s;
    vector<ll> arr(n - 1);
    for (int i = 0; i < n-1; i++)
    {
        cin >> arr[i];
    }
    vector<ll> prefix(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    int ans = 1;

    for (int l = 0; l <= s; l++)
    {
        for (int r = s; r < n; r++)
        {

            ll leftDis = prefix[s] - prefix[l];
            ll rightDis = prefix[r] - prefix[s];

            ll totalDis = prefix[r] - prefix[l];

            if ((totalDis + min(1LL*leftDis,1LL*rightDis)) <= L)
            {
                ans = max(ans, r - l + 1);
            }
        }
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}