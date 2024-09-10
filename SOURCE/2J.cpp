#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

bool check(vector<pair<int, int>> res) {
    int tmp = res[0].second;
    for (int i = 1; i < res.size(); i++) {
        if (res[i].second != tmp) return false;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    vector<pair<int, int>> res;
    for (pair<int, int> x : a) res.push_back(x);
    if (res.size() <= 1 || check(res)) cout << "NONE";
    else {
        sort(res.begin(), res.end(), cmp);
        int tmp = res[0].second;
        int i = 0;
        while (i < res.size() && res[i].second == tmp) i++;
        cout << res[i].first;
    }
    return 0;
}