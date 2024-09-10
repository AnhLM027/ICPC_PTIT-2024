#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    ll res = 0;
    for (int b = k + 1; b <= n; ++b) {
        res += (n / b) * (b - k);
        if (n % b >= k) {
            res += n % b - k + 1;
        }
    }
    if (k == 0) res -= n;
    cout << res;
    return 0;
}