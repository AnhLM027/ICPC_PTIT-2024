#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

#define limit 1000000
bool check[limit] = { false };

void sang() {
    check[0] = check[1] = true;
    for (int i = 2; i <= sqrt(limit); i++) {
        if (!check[i]) {
            for (int j = i * i; j <= limit; j += i) check[j] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sang();
    int n; cin >> n;
    int cnt = 0;
    for (int i = 2; i <= n / 2; i++) {
        if (!check[i] && !check[n - i]) cnt++;
    }
    cout << cnt;
    return 0;
}