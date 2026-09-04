#include <iostream>
#include<set>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    set<int> s;
    long long ans = 0;

    int l = 0;

    for (int r = 0; r < n; r++) {

        while (s.count(a[r])) {
            s.erase(a[l]);
            l++;
        }

        s.insert(a[r]);

        ans += r - l + 1;
    }

    cout << ans << '\n';
}