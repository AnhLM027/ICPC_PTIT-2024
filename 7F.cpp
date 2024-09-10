#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007

ll binPow(ll a, int b) {
    ll tich = 1;
    while (b) {
        if (b & 1) tich = (tich * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return tich;
}

int main() {
    int n, loai;
    cin >> n >> loai;
    int a[100];
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
        if (a[1] & 1) cout << "1\n";
        else if (loai & 1) cout << "0\n";
        else cout << "2";
    }
    else cout << binPow(2, n - 1);
    return 0;
}