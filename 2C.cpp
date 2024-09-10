#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(2 * n);
    for (int& x : a) cin >> x;
    vector<int> tmp = a;
    sort(tmp.begin(), tmp.end());
    queue<pair<vector<int>, int>> qe;
    qe.push({ a,0 });
    set<vector<int>> se;
    while (!qe.empty()) {
        auto top = qe.front(); qe.pop();
        vector<int> b = top.first;
        if (b == tmp) {
            cout << top.second;
            return 0;
        }
        vector<int> c = b;
        for (int i = 0; i <= 2 * n - 2; i += 2) {
            swap(b[i], b[i + 1]);
        }
        if (!se.count(b)) qe.push({ b,top.second + 1 }); se.insert(b);
        for (int i = 0; i < n; i++) {
            swap(c[i], c[n + i]);
        }
        if (!se.count(c)) qe.push({ c,top.second + 1 }); se.insert(c);
    }
    cout << -1;
    return 0;
}