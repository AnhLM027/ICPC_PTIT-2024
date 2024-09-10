#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int l = s.length();
    int n; cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x - 1] = (cnt[x - 1] + 1) % 2;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] & 1) {
            for (int j = i; j < l / 2; j++) {
                swap(s[j], s[l - j - 1]);
            }
        }
    }
    cout << s;
    return 0;
}