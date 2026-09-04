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

ll helper(vector<ll> nums, int idx, ll target, ll ans)
{
    if (idx == nums.size())
    {
        return ans;
    }
    ll take = ans;

    if (ans + nums[idx] <= target)
    {
        take = helper(nums, idx + 1, target, ans + nums[idx]);
    }
    ll notTake = helper(nums, idx + 1, target, ans);

    return max(take, notTake);
}
void solve()
{
    int n;
    cin >> n;

    vector<ll> nums;
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
        sum += x;
    }

    ll target = sum / 2;

    ll best = helper(nums, 0, target, 0);

    cout << (sum - (2 * best)) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}