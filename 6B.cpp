#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



ll dp[100000];
void init() {
    dp[0] = 3;
    dp[1] = 10;
    for (int i = 2; i < 50; i++) {
        dp[i] = dp[i - 1] * 2 + i + 3;
    }
}

char chia(ll k, ll n) {
    if (k == 0) return n == 1 ? 'a' : 'c';
    if (n <= dp[k - 1]) return chia(k - 1, n);
    if (n > dp[k - 1] + k + 3) return chia(k - 1, n - dp[k - 1] - k - 3);
    else {
        n -= dp[k - 1];
        if (n == 1) return 'a';
        else return 'c';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    int n; cin >> n;
    int ind = -1;
    for (int i = 0; i <= 50; i++) {
        if (n <= dp[i]) {
            ind = i;
            break;
        }
    }
    cout << chia(ind, n) << endl;
    //cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
    return 0;
}