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
    string s;
    cin >> s;
    int n = s.size();

    string ans;
    for(int i = 0;i<n;i++){
        if(i == n-1){
            ans += s[i];
        }else{
            ans += s[i];
            ans += 'o';
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}