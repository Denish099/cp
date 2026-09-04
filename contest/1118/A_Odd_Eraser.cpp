#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int gcd(int a, int b)
{
    while (b)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << gcd(arr[0], arr[n - 1]) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}