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
bool isMinOrMax(int val,set<int>& st){
    if((*st.begin()) == val){
        return false;
    }

    if((*st.rbegin()) == val){
        return false;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }

    set<int> st(arr.begin(),arr.end());

    int i =0,j=n-1;

    while(i < j){
        if(!isMinOrMax(arr[i],st)){
            st.erase(arr[i]);
            i++;
            continue;
        }

        if(!isMinOrMax(arr[j],st)){
            st.erase(arr[j]);
            j--;
            continue;
        }
        break;
    }

    if(i == j){
        cout << "-1\n";
        return;
    }
    cout << i+1 << " " << j +1<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}