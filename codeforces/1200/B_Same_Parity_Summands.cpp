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
    int n, k;
    cin >> n >> k;

   
    int el = n - (k - 1);

    if (el > 0 && el % 2 == 1)
    {
        cout << "YES\n";

        for (int i = 0; i < k - 1; i++)
        {
            cout << 1 << " ";
        }

        cout << el << endl;
        return;
    }

    
    el = n - 2 * (k - 1);

    if (el > 0 && el % 2 == 0)
    {
        cout << "YES\n";

        for (int i = 0; i < k - 1; i++)
        {
            cout << 2 << " ";
        }

        cout << el << endl;
        return;
    }

    cout << "NO\n";
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