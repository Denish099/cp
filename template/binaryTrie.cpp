#include<iostream>
using namespace std;

const int MAXN = 1000005;
const int LOG = 30;

int ch[MAXN][2];
int cnt[MAXN];
int sz = 1;

void insert(int n){
    int curr = 0;
    for(int i = LOG;i>=0;i--){
        int bit = (n >> i) & 1;

        if(!ch[curr][bit]){
            ch[curr][bit] = sz++;
        }

        curr = ch[curr][bit];
        cnt[curr]++;
    }
}

void erase(int x){
    int curr = 0;

    for(int i = LOG;i>=0;i--){
        int bit = (x >> i) & 1;
        curr = ch[curr][bit];
        cnt[curr]--;
    }
}

bool exists(int x) {
    int cur = 0;

    for (int i = LOG; i >= 0; i--) {
        int bit = (x >> i) & 1;

        if (!ch[cur][bit])
            return false;

        cur = ch[cur][bit];
    }

    return cnt[cur] > 0;
}