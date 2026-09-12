#include <iostream>
#include <vector>

using namespace std;

struct DSU
{
    vector<int> parent;
    vector<int> size;

    DSU(int n)
    {
        parent.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
        {
            return false;
        }

        if (a < b)
        {
            swap(a, b);
        }

        parent[b] = a;
        size[a] += size[b];

        return true;
    }
};

xvoid solve() {
    int n, s;
    ll L;

    cin >> n >> s >> L;
    --s; // 0-indexed

    vector<ll> a(n - 1);

    for (auto &x : a)
        cin >> x;

    // pref[i] = distance from town 0 to town i
    vector<ll> pref(n, 0);

    for (int i = 0; i < n - 1; i++) {
        pref[i + 1] = pref[i] + a[i];
    }

    int ans = 1; // town S itself

    for (int l = 0; l <= s; l++) {

        for (int r = s; r < n; r++) {

            ll leftDist = pref[s] - pref[l];
            ll rightDist = pref[r] - pref[s];
            ll totalDist = pref[r] - pref[l];

            ll cost = totalDist + min(2 * leftDist,
                                      2 * rightDist);

            if (cost <= L) {
                ans = max(ans, r - l + 1);
            }
        }
    }

    cout << ans << '\n';
}