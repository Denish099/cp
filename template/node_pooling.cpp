#include <iostream>
#include <string>
using namespace std;

const int MAXN = 1000005;

int ch[MAXN][26];
bool isEnd[MAXN];
int sz = 1;

void insert(string s)
{
    int cur = 0;

    for (char c : s)
    {
        int x = c - 'a';

        if (ch[cur][x] == 0)
            ch[cur][x] = sz++;

        cur = ch[cur][x];
    }

    isEnd[cur] = true;
}

bool search(string s)
{
    int cur = 0;

    for (char c : s)
    {
        int x = c - 'a';

        if (ch[cur][x] == 0)
            return false;

        cur = ch[cur][x];
    }

    return isEnd[cur];
}

bool startsWith(string s)
{
    int cur = 0;

    for (char c : s)
    {
        int x = c - 'a';

        if (ch[cur][x] == 0)
            return false;

        cur = ch[cur][x];
    }

    return true;
}

void solve()
{
    insert("apple");
    insert("app");
    insert("bat");

    cout << search("apple") << '\n';  // 1
    cout << search("app") << '\n';    // 1
    cout << search("ap") << '\n';     // 0
    cout << search("banana") << '\n'; // 0

    cout << startsWith("app") << '\n'; // 1
    cout << startsWith("bat") << '\n'; // 1
    cout << startsWith("ban") << '\n'; // 0
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}