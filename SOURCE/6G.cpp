#include<bits/stdc++.h>
using namespace std;

#define ll long long



set<string> res;

void solve(int a, int b, int c) {
    if (a != 0) {
        double delta = b * b - 4 * a * c;
        if (delta >= 0) {
            double x1 = (-b + sqrt(delta)) / ((double)2 * a);
            double x2 = (-b - sqrt(delta)) / ((double)2 * a);
            stringstream ss1, ss2;
            ss1 << fixed << setprecision(9) << x1;
            ss2 << fixed << setprecision(9) << x2;
            string s1 = ss1.str();
            string s2 = ss2.str();
            res.insert(s1);
            res.insert(s2);
            //cout << s1 << " " << s2 << endl;
        }
    }
    else {
        if (b != 0) {
            double x = (double)-c / b;
            stringstream ss;
            ss << fixed << setprecision(9) << x;
            string s = ss.str();
            res.insert(s);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    for (int i = 1; i <= n; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            cout << "-1";
            return 0;
        }
        solve(a, b, c);
    }
    cout << res.size();
    return 0;
}