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
    int d, totalTime;
    cin >> d >> totalTime;

    vector<vector<int>> arr(d, vector<int>(2));

    int minSum = 0;
    int maxSum = 0;

    for (int i = 0; i < d; i++) {
        cin >> arr[i][0] >> arr[i][1];

        minSum += arr[i][0];
        maxSum += arr[i][1];
    }


    if (totalTime < minSum || totalTime > maxSum) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;


    vector<int> ans(d);

    for (int i = 0; i < d; i++) {
        ans[i] = arr[i][0];
    }


    int remaining = totalTime - minSum;

    for (int i = 0; i < d; i++) {


        int capacity = arr[i][1] - arr[i][0];

        int add = min(remaining, capacity);

        ans[i] += add;
        remaining -= add;
    }

    for (int i = 0; i < d; i++) {
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}