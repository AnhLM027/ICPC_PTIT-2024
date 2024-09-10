#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<string, int> res;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string tmp; cin >> tmp;
        sort(tmp.begin(), tmp.end());
        res[tmp]++;
    }
    for (pair<string, int> x : res) {
        int tmp = x.second;
        if (tmp >= 2) cnt += (ll)tmp * (tmp - 1) / 2;
    }
    cout << cnt;
    return 0;
}