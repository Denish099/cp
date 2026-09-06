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

int arr[100005], seg[4 * 100005];

void build(int idx, int low, int high)
{
    if (low == high)
    {
        seg[idx] = arr[low];
        return;
    }

    int mid = (low + high) / 2;

    build(2 * idx + 1, low, mid);
    build(2 * idx + 2, mid + 1, high);

    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}

void update(int idx, int low, int high, int pos, int value)
{
    if (low == high)
    {
        arr[pos] = value;
        seg[idx] = value;
        return;
    }

    int mid = (low + high) / 2;

    if (pos <= mid)
    {
        update(2 * idx + 1, low, mid, pos, value);
    }
    else
    {
        update(2 * idx + 2, mid + 1, high, pos, value);
    }

    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int query(int idx, int low, int high, int l, int r)
{
    if (low >= l && high <= r)
    {
        return seg[idx];
    }

    if (high < l || low > r)
    {
        return -INF;
    }

    int mid = (low + high) / 2;

    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, high, l, r);

    return max(left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    build(0, 0, n - 1);

    int q;
    cin >> q;

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int l, r;
            cin >> l >> r;

            cout << query(0, 0, n - 1, l, r) << endl;
        }
        else if (type == 2)
        {
            int pos, value;
            cin >> pos >> value;

            update(0, 0, n - 1, pos, value);
        }
    }

    return 0;
}