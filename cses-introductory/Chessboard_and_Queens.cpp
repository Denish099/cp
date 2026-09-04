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

int ans = 0;

bool safe(int r, int c, vector<string> &s)
{
    for (int i = r - 1; i >= 0; i--)
    {
        if (s[i][c] == 'q')
            return false;
    }

    for (int i = r - 1, j = c - 1;
         i >= 0 && j >= 0;
         i--, j--)
    {
        if (s[i][j] == 'q')
            return false;
    }

    for (int i = r - 1, j = c + 1;
         i >= 0 && j < 8;
         i--, j++)
    {
        if (s[i][j] == 'q')
            return false;
    }

    return true;
}

void solve(int r, vector<string> &s)
{
    if (r == 8)
    {
        ans++;
        return;
    }

    for (int c = 0; c < 8; c++)
    {
        if (s[r][c] != '.')
            continue;

        if (safe(r, c, s))
        {
            // Choose
            s[r][c] = 'q';

            solve(r + 1, s);

            s[r][c] = '.';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> s(8);

    for (int i = 0; i < 8; i++)
    {
        cin >> s[i];
    }

    solve(0, s);

    cout << ans << endl;

    return 0;
}