#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1000006
#define maxx 100000009
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
double solve(int n, int k, vector<int>& D) {
    if (k == 1) {
        vector<int> sortedD = D;
        sort(sortedD.begin(), sortedD.end());
        int td = sortedD[n / 2];
        double cost = 0;
        for (int i = 0; i < n; ++i) {
            cost += abs(D[i] - td);
        }
        return cost;
    }
    else if (k == 2) {
        double tbc = 0;
        for (int i = 0; i < n; ++i) {
            tbc += D[i];
        }
        tbc /= n;
        double cost = 0;
        for (int i = 0; i < n; ++i) {
            cost += (D[i] - tbc) * (D[i] - tbc);
        }
        return cost;
    }
    return 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> D(n);
    for (int i = 0; i < n; ++i) {
        cin >> D[i];
    }
    double result = solve(n, k, D);
    cout << fixed << setprecision(2) << result;
}