#include <bits/stdc++.h>
using namespace std;


typedef unsigned long long ull;

ull MOD;


ull mul(ull a, ull b) {
    ull ans = 0;
    while (b > 0) {
        if (b % 2 == 1) ans = (ans + a) % MOD;
        a = (a * 2) % MOD;
        b /= 2;
    }
    return ans;
}

vector<vector<ull>> fibo(vector<vector<ull>> a, vector<vector<ull>> b) {
    vector<vector<ull>> res(2, vector<ull>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                res[i][j] = (res[i][j] + mul(a[i][k], b[k][j])) % MOD;
            }
        }
    }
    return res;
}

ull binPow(vector<vector<ull>> a, ull n) {
    vector <vector<ull>> tmp(2, vector<ull>(2));
    tmp[0][0] = 1; tmp[0][1] = 1;
    tmp[1][0] = 1; tmp[1][1] = 0;
    if (n == 1) return a[0][1];
    while (n > 0) {
        if (n & 1) tmp = fibo(tmp, a);
        n /= 2;
        a = fibo(a, a);
    }
    return tmp[0][1];
}

ull solve(ull n) {
    vector<vector<ull>> a(2, vector<ull>(2));
    a[0][0] = 1; a[0][1] = 1;
    a[1][0] = 1; a[1][1] = 0;
    return binPow(a, n - 1);
}

ull gcd(ull a, ull b) {
    while (a != 0) { ull x = a; a = b % a; b = x; }
    return b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ull n, m; cin >> n >> m >> MOD;
        ull uc = gcd(n, m);
        cout << solve(uc) << endl;
    }
    return 0;
}