#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i <= 100; i++) {
        if (n - 4 * i >= 0 && (n - 4 * i) % 7 == 0) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}