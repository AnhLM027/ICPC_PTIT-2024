#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}


int main() {
    vector<pair<int, int>> res(3);
    for (int i = 0; i < 3; i++) {
        cin >> res[i].first >> res[i].second;
        if (res[i].first < res[i].second) swap(res[i].first, res[i].second);
    }
    sort(res.begin(), res.end(), cmp);
    int a1, a2, a3, b1, b2, b3;
    a1 = res[0].first, b1 = res[0].second;
    a2 = res[1].first, b2 = res[1].second;
    a3 = res[2].first, b3 = res[2].second;
    if (a1 == a2 == a3) {
        if (b1 + b2 + b3 == a1) cout << a1;
        else cout << 0;
    }
    else {
        if (a1 == a2 && a1 + b3 == a3 && b1 + b2 == a3) cout << a3;
        else if (b1 == b2 && a1 + a2 == a3 && b1 + b3 == a3) cout << a3;
        else if (a1 == b2 && a1 + b3 == a3 && b1 + a2 == a3) cout << a3;
        else if (b1 == a2 && b1 + a2 == a3 && a1 + b2 == a3) cout << a3;
        else cout << 0;
    }
}