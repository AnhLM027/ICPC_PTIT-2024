#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;


int main() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll maxx = *max_element(a.begin(), a.end());
    map<int, bool> check;
    for (int i = 0; i < n; i++) {
        for (int j = a[i] * 2; j <= maxx; j += a[i]) {
            check[j] = true;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!check[a[i]] && mp[a[i]] == 1) cnt++;
    }
    cout << cnt;
    return 0;
}