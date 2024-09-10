#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()

using namespace std;

typedef long long ll;

string s;

int solve() {
    vector<char> vp;
    int res = 0;
    int tmp;
    for (int i = 0; i < s.length(); i++)
    {
        vp.pb(s[i]);
        while (vp.sz >= 2 && ((vp[vp.sz - 1] == '1' && vp[vp.sz - 2] == '0')
            || (vp[vp.sz - 1] == '0' && vp[vp.sz - 2] == '1'))) {
            vp.pop_back();
            vp.pop_back();
        }
    }
    res = s.length() - vp.size();
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    cout << solve() << endl;
    return 0;
}