#include <bits/stdc++.h>
#define MAXN 20000005
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;


typedef long long ll;


vector<int> Prime;
ll dp[20000005];

void prime() {
    for (int i = 2; i <= 20000001; i++) dp[i] = i;
    for (int i = 2; i * i <= 20000001; i++) {
        if (dp[i] == i) {
            Prime.push_back(i);
            for (int j = i * i; j <= 20000001; j += i) {
                dp[j] = i;
            }
        }
    }
    for (int i = 2; i <= 20000001; i++) {
        if (dp[i] == i) continue;
        int max1 = i / dp[i];
        dp[i] = max(dp[i], dp[max1]);
    }
}


int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int snt(ll n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

ll find(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) return -1;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == 0 && a[i + 1] == 0) return -1;
        if (a[i] != 0 && a[i + 1] != 0 && gcd(a[i], a[i + 1]) != 1) return -1;
    }
    bool check_0 = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1) return -1;
        if (a[i] == 0) check_0 = true;
    }
    set<int> res;
    if (!check_0) return 1;
    for (int i = 0; i < n; i++) {
        if ((i > 0 && a[i - 1] == 0) || (i <= n - 2 && a[i + 1] == 0)) {
            while (a[i] > 1) {
                res.insert(dp[a[i]]);
                a[i] /= dp[a[i]];
            }
        }
    }
    for (int i = 2; i < MAXN; i++) {
        if (dp[i] == i && !res.count(i)) {
            return i;
        }
    }
    return -1;
}

int main() {
    prime();
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    cout << find(a) << endl;
}