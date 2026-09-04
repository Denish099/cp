#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> a;

void solve(int idx, int rem) {

   
    if (idx == N) {
        if (rem % N == 0) {
            a.push_back(rem / N);

            for (int x : a)
                cout << x << ' ';
            cout << '\n';

            a.pop_back();
        }
        return;
    }

    
    for (int x = 0; x <= rem / idx; x++) {
        a.push_back(x);

        solve(idx + 1, rem - idx * x);

        a.pop_back();
    }
}

int main() {
    cin >> N >> K;

    solve(1, K);

    return 0;
}