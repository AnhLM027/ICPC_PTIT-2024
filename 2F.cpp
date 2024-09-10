#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int ind_1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) ind_1 = i;
    }
    int dem = 0, check = 0;
    int i = ind_1 - k + 1;
    while (i >= 0) {
        dem++;
        i -= (k - 1);
    }
    if (i < 0) check = i + k - 1;
    i = ind_1 + k - 1;
    while (i < n) {
        dem++;
        i += k - 1;
    }
    check += n - 1 - (i - k + 1);
    while (check > 0) {
        dem++;
        check -= k;
    }
    cout << dem;
    return 0;
}