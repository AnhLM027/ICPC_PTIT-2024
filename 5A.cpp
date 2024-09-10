#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;


int main() {
    string s; cin >> s;
    string t; cin >> t;
    unordered_map<char, char> map_s;
    unordered_map<char, char> map_t;
    int n = s.length();
    bool check = true;
    for (int i = 0; i < n; ++i) {
        char tmp1 = s[i];
        char tmp2 = t[i];
        if (map_s.count(tmp1)) {
            if (map_s[tmp1] != tmp2) {
                check = false;
                break;
            }
        }
        else map_s[tmp1] = tmp2;
        if (map_t.count(tmp2)) {
            if (map_t[tmp2] != tmp1) {
                check = false;
                break;
            }
        }
        else map_t[tmp2] = tmp1;
    }
    if (check) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}