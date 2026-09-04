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
    int A,B;
    cin >> A >> B;

    int add = A + B;
    int sub = A - B;
    int mul = A * B;
    int div = A / B;

    if(add == 9 || sub == 9 || mul == 9 || (div == 9 && A % B == 0)){
        cout<< "Nine"<<endl;
    }else{
        cout<< "Nein"<<endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

        solve();
    
    
    return 0;
}