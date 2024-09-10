#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;


int main() {
    int k; cin >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 0; i < a[0]; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    for (int i = 1; i < k; i++) {
        map<int, int> mp2;
        for (int j = 0; j < a[i]; j++) {
            int x; cin >> x;
            if (mp[x] > 0) mp2[x]++;
        }
        mp = mp2;
    }
    if (mp.size() == 0) cout << "NO";
    else {
        auto it = mp.begin();
        pair<int, int> tmp = *it;
        cout << tmp.first;
    }
    return 0;
}