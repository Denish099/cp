#include <iostream>
#include <set>
using namespace std;

void solve()
{
    int x, n;
    cin >> x >> n;

    set<int> s = {0, x};
    multiset<int> m = {x};

    while (n--)
    {
        int p;
        cin >> p;

        auto r = s.lower_bound(p);
        auto l = prev(r);

        m.erase(m.find(*r - *l));

        m.insert(*r - p);
        m.insert(p - *l);

        s.insert(p);

        cout << *m.rbegin() << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}