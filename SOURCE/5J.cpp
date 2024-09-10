#include <bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    unsigned int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n < 3) {
        cout << 0;
        return 0;
    }
    ll ans = 0;
    multiset<ll> res;
    int l = 0;
    for (int r = 0; r < n; r++) {
        res.insert(a[r]);
        while (res.size() > 2) {
            auto it1 = res.begin();
            auto it2 = next(it1);
            auto it3 = prev(res.end());
            if (*it1 + *it2 > *it3) {
                ans = max(ans, (ll)res.size());
                break;
            }
            else {
                res.erase(res.find(a[l]));
                l++;
            }
        }
    }
    while (res.size() > 2) {
        auto it1 = res.begin();
        auto it2 = next(it1);
        auto it3 = prev(res.end());

        if (*it1 + *it2 > *it3) {
            ans = max(ans, (ll)res.size());
            break;
        }
        else {
            res.erase(res.find(a[l]));
            l++;
        }
    }
    cout << ans;
    return 0;
}