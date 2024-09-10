#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main() {
    int l; cin >> l;
    string s; cin >> s;
    ll cong = 0, tru = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] == '+') cong++;
        else tru++;
    }
    int q; cin >> q;
    while (q--) {
        ll a, b; cin >> a >> b;
        if (a == b && cong == tru) {
            cout << "YES\n";
            continue;
        }
        if (a == b && cong != tru) {
            cout << "NO\n";
            continue;
        }
        ll tmp = (tru - cong) * b;
        if (tmp % (a - b) != 0) cout << "NO\n";
        else {
            tmp /= (a - b);
            ll m = tmp;
            ll M = tru + tmp;
            if ((m >= 0 && m <= cong) || (m < 0 && M >= 0)) {
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }

    return 0;
}