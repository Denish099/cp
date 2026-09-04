#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());


    int pos = 0;

    for (int i = 1; i < n - 1; i++) {
        if (a[i + 1] - a[i] < a[pos + 1] - a[pos]) {
            pos = i;
        }
    }

    vector<int> ans;


    ans.push_back(a[pos]);


    for (int i = pos + 2; i < n; i++) {
        ans.push_back(a[i]);
    }


    for (int i = 0; i < pos; i++) {
        ans.push_back(a[i]);
    }


    ans.push_back(a[pos + 1]);

    for (int x : ans)
        cout << x << ' ';

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}