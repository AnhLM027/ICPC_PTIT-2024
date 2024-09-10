#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int cnt[1000000];

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    fill(cnt, cnt + 1000000, 0);
    int maxx = -1e9;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; cnt[a[i]]++;
        maxx = max(maxx, a[i]);
    }
    for (int i = maxx; i > 1; i--) {
        int dem = 0;
        for (int j = i; j <= maxx; j += i) {
            dem += cnt[j];
            if (dem >= 2) {
                cout << i << endl;
                return;
            }
        }
    }
    cout << 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int te; cin >> te;
    while (te--) {
        solve();
    }
    return 0;
}