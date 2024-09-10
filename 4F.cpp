#include <bits/stdc++.h>
using namespace std;


typedef long long ll;



int main() {
    int n1, n2, n3; cin >> n1 >> n2 >> n3;
    unordered_map<string, int> mp1;
    vector<string> a;
    string s; int x;
    for (int i = 0; i < n1; i++) {
        cin >> s >> x;
        mp1[s] += x;
        a.push_back(s);
    }
    unordered_map<string, int> mp2;
    for (int i = 0; i < n2; i++) {
        cin >> s >> x;
        if (mp1[s] > 0) mp2[s] += x;
    }
    unordered_map<string, int> mp3;
    for (int i = 0; i < n3; i++) {
        cin >> s >> x;
        if (mp1[s] > 0) mp3[s] += x;
    }
    vector<string> res;
    for (auto x : mp1) {
        string s = x.first;
        if (mp2.find(s) != mp2.end() && mp3.find(s) != mp3.end()
            && mp1[s] >= 20 && mp2[s] >= 20 && mp3[s] >= 20) {
            res.push_back(s);
        }
    }
    sort(res.begin(), res.end(), [&a](const string& x, const string& y) {
        auto itx = find(a.begin(), a.end(), x);
        auto ity = find(a.begin(), a.end(), y);
        return (itx < ity);
        });
    cout << res.size() << " ";
    for (string s : res) cout << s << " ";
}