#include <string>

using namespace std;

struct Node
{
    Node *list[26] = {};
    bool isEnd = false;
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string s)
    {
        Node *curr = root;

        for (int i = 0; i < s.size(); i++)
        {
            int x = s[i] - 'a';

            if (curr->list[x] == nullptr)
            {
                curr->list[x] = new Node();
            }

            curr = curr->list[x];
        }

        curr->isEnd = true;
    }

    bool search(string s){
        Node* curr = root;

        for(int i = 0;i<s.size();i++){
            int x = s[i] - 'a';
            if(curr->list[x] == nullptr){
                return false;
            }

            curr = curr->list[x];
        }
        return curr->isEnd;
    }

    bool startsWith(string s){
        Node* curr = root;
        for(int i = 0;i<s.size();i++){
            int x = s[i] -'a';
            if(curr->list[x] == nullptr){
                return false;
            }
            curr = curr->list[x];
        }

        return true;
    }
};