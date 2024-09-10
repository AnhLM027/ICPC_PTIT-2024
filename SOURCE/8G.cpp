#include<bits/stdc++.h>
using namespace std;

typedef long long ll;




int main() {
    string a, b; cin >> a >> b;
    int l = b.length();
    for (int i = 0; i < a.length() - l + 1; i++) {
        string tmp = a.substr(i, l);
        if (tmp == b) cout << i + 1 << " ";
    }
}