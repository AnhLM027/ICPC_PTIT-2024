#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll b; cin >> b;
        ll mod1 = 0;
        ll mod2 = 1;
        ll modn = 1;
        ll cnt = 0;
        for (ll i = 0; i < LLONG_MAX; i++) {
            ll tmp = mod1 + mod2;
            modn = tmp % b;
            cnt++;
            if (modn == 1 && modn + mod2 == b) break;
            mod1 = mod2; mod2 = modn;
        }
        cout << cnt + 2 << endl;
    }
    //cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
    return 0;
}