#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, st, en, u, d;
    cin >> n >> st >> en >> u >> d;
    int cnt = -1;
    queue<pair<int, ll>> qe;
    qe.push({ st,0 });
    set<int> se;
    while (!qe.empty()) {
        pair<int, ll> top = qe.front(); qe.pop();
        int tang = top.first;
        if (tang == en) {
            cnt = top.second;
            break;
        }
        if (u > 0 && tang + u <= n && se.find(tang + u) == se.end()) {
            qe.push({ tang + u,top.second + 1 });
            se.insert(tang + u);
        }
        if (d > 0 && tang - d >= 0 && se.find(tang - d) == se.end()) {
            qe.push({ tang - d,top.second + 1 });
            se.insert(tang - d);
        }
    }
    cout << cnt;
    return 0;
}