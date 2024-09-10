#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll n;
set<ll> se;

void Try() {
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            if (i == j) continue;
            queue<ll> qe;
            qe.push(i); qe.push(j);
            while (!qe.empty()) {
                ll top = qe.front(); qe.pop();
                if (top == 0 || top > n) continue;
                se.insert(top);
                qe.push(top * 10 + i); qe.push(top * 10 + j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    Try();
    cout << se.size();
    return 0;
}