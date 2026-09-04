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
#include <bitset> 
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

string toBinaryString(int num, int n) {
    string s = "";
    for (int i = n - 1; i >= 0; i--) {
        s += ((num >> i) & 1) ? '1' : '0';
    }
    return s;
}

void solve() {
    int n;
    cin >> n;

    int total = 1 << n;
    for(int i = 0; i < total; i++){
        int gray_value = i ^ (i >> 1);
        
        cout << toBinaryString(gray_value, n) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}