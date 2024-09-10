#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    multiset<int> se;
    int l = 0;
    se.insert(a[0]);
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        auto it = se.begin();
        if (a[i] <= *it) cnt++;
        se.insert(a[i]);
    }
    cout << cnt;
    //cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
    return 0;
}