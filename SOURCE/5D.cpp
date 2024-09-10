#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;


int main() {
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = a[k - 1] - a[0];
    for (int i = 1; i < n - k + 1; i++)
    {
        ans = min(ans, a[i + k - 1] - a[i]);
    }
    cout << ans;
    return 0;
}