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
    int n, m;
    cin >> n >> m;

    vector<int> freq(m+1);
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    vector<int> suffix(m+2);

    for(int i = m;i>=0;i--){
        suffix[i] = suffix[i+1] + freq[i];
    }

    int ans = 0;
    int curr = 0;
    for(int k = 1;k<=m;k++){
        curr = freq[k];
        curr += suffix[k+1];

        if(2*k <= m){
            curr +=freq[2*k];
        }
        ans = max(ans,curr);

    }

    cout << ans << endl;
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