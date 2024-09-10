#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



int main() {
    int n; cin >> n;
    vector<ll> a(n), b(n), d(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) d[i] = a[i] - b[i];
    int cnt = 0;
    sort(d.begin(), d.end(), greater<ll>());
    if (d[0] < 0) cout << "0";
    else {
        ll sum = d[0];
        cnt = 1;
        for (int i = 1; i < n; i++) {
            sum += d[i];
            if (sum >= 0) cnt++;
            else break;
        }
        cout << cnt;
    }
    return 0;
}