#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for (ll& x : a) cin >> x;
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
    ll cnt = 0;
    unordered_map<ll, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        a[i] %= m;
        cnt += mp[a[i]];
        mp[a[i]]++;
    }
    cout << cnt;
    return 0;
}