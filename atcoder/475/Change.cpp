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

    for (auto &i : arr)
    {
        cin >> i;
    }

    int ones = 0;
    int tens = 0;
    int hundreds = 0;

    for (int i = 0; i < n; i++)
    {
        int x = arr[i];

        int mini = ((x + 1000) / 1000) * 1000;

        int rem = mini - x;

        // cout << rem <<" ";

        ones += (rem % 10);
        rem /= 10;
        tens += rem % 10;
        rem = (rem / 10);
        hundreds += (rem % 10);
    }

    cout << ones << " " << tens << " " << hundreds;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}