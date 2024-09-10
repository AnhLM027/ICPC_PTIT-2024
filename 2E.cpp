#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        while (a[i] % 2 == 0) {
            cnt++; a[i] /= 2;
        }
    }
    cout << cnt;
    return 0;
}