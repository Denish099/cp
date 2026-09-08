#include <iostream>
#include <string>
using namespace std;

const int LOG = 30;

struct Node
{
    Node *list[2] = {};
    int cnt = 0;
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int n)
    {
        Node *curr = root;
        curr->cnt++;

        for (int i = LOG; i >= 0; i--)
        {
            int bit = (n >> i) & 1;

            if (curr->list[bit] == nullptr)
            {
                curr->list[bit] = new Node();
            }

            curr = curr->list[bit];
            curr->cnt++;
        }
    }

    void erase(int n)
    {
        Node *curr = root;
        curr->cnt--;

        for (int i = LOG; i >= 0; i--)
        {
            int bit = (n >> i) & 1;

            curr = curr->list[bit];
            curr->cnt--;
        }
    }

    int getMaxXor(int n)
    {
        Node *curr = root;
        int ans = 0;

        for (int i = LOG; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            int want = bit ^ 1;

            if (curr->list[want] != nullptr &&
                curr->list[want]->cnt > 0)
            {
                ans |= (1 << i);
                curr = curr->list[want];
            }
            else
            {
                curr = curr->list[bit];
            }
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie trie;

    trie.insert(0);

    int q;
    cin >> q;

    while (q--)
    {
        char op;
        int x;

        cin >> op >> x;

        if (op == '+')
        {
            trie.insert(x);
        }
        else if (op == '-')
        {
            trie.erase(x);
        }
        else
        {
            cout << trie.getMaxXor(x) << '\n';
        }
    }

    return 0;
}