#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> arr(n + 2, 0);
    vector<int> pos(n + 2, 0);

    for (int k = 1; k <= n; k++) {
        cin >> arr[k];
        pos[arr[k]] = k;
    }

    int rounds = 1;
    for (int k = 1; k < n; k++) {
        if (pos[k] > pos[k + 1]) {
            rounds++;
        }
    }

    while (m--) {
        int i, j;
        cin >> i >> j;

        if (i > j) swap(i, j);

        int x = arr[i];
        int y = arr[j];


        if (pos[x + 1] > i && pos[x + 1] < j) rounds++;
        if (pos[x - 1] > i && pos[x - 1] < j) rounds--;
        if (pos[y + 1] > i && pos[y + 1] < j) rounds--;
        if (pos[y - 1] > i && pos[y - 1] < j) rounds++;

        if (x == y + 1) rounds--;
        if (x == y - 1) rounds++;

       
        swap(arr[i], arr[j]);
        pos[arr[i]] = i;
        pos[arr[j]] = j;

        cout << rounds << "\n";
    }

    return 0;
}