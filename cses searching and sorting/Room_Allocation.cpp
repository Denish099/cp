#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<pair<int,int>, int>> a(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {{x, y}, i};
    }

    sort(a.begin(), a.end());

    set<pair<int,int>> rooms;
    vector<int> ans(n);

    int cnt = 0;

    for (auto x : a) {
        int arrival = x.first.first;
        int departure = x.first.second;
        int idx = x.second;

        
        auto it = rooms.lower_bound({arrival, -1});

        if (it == rooms.begin()) {
           
            cnt++;
            ans[idx] = cnt;
            rooms.insert({departure, cnt});
        }
        else {
            --it;

            int room = it->second;
            rooms.erase(it);

            ans[idx] = room;
            rooms.insert({departure, room});
        }
    }

    cout << cnt << '\n';

    for (int x : ans)
        cout << x << ' ';
}