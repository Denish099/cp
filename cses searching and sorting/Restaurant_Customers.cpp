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

void solve() {
    int n;
    cin >> n;

    vector<ll> arrival(n), gone(n);

    for(int i = 0; i < n; i++) {
        cin >> arrival[i] >> gone[i];
    }

    sort(all(arrival));
    sort(all(gone));

    int i = 0, j = 0;
    ll curr = 0;
    ll ans = 0;

    while(i < n) {
        if(arrival[i] < gone[j]) {
         
            curr++;
            ans = max(ans, curr);
            i++;
        } else {
        
            curr--;
            j++;
        }
    }

    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}