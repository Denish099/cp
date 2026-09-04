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

    vector<ll> arr(n);
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    ll median = 0;
    if(n % 2 == 1){
        median = arr[n/2];
    }else{
        median = (arr[n/2] + arr[n/2 - 1]) / 2;
    }

    ll ans = 0;

    for(int i = 0;i<n;i++){
        ans += abs(median - arr[i]);
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}