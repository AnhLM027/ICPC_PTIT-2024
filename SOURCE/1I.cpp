#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    ll sum = 0;
    while (cin >> s) {
        if (s.length() > 18) continue;
        bool ok = true;
        for (char x : s) {
            if (!isdigit(x)) ok = false;
        }
        if (ok) sum += stoll(s) > INT_MAX ? stoll(s) : 0;
    }
    cout << sum;
    return 0;
}