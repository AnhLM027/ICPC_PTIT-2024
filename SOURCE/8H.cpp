#include<bits/stdc++.h>
using namespace std;

typedef long long ll;




int main() {
    int a, b, k; cin >> a >> b >> k;
    int cnt = 0;
    if (a < b) swap(a, b);
    for (int i = b; i >= 1; i--) {
        if (a % i == 0 && b % i == 0) cnt++;
        if (cnt == k) {
            cout << i;
            return 0;
        }
    }
}