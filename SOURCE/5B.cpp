#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1000006
#define maxx 100000009
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
vector<long long> uoc(long long x) {
    vector<long long> div;
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            div.push_back(i);
            if (i != x / i) {
                div.push_back(x / i);
            }
        }
    }
    sort(div.begin(), div.end(), greater<long long>());
    return div;
}
int main() {
    long long N, M;
    cin >> N >> M;
    vector<long long> div = uoc(M);
    long long res = 1;
    for (long long d : div) {
        if (d * N <= M) {
            res = d;
            break;
        }
    }
    cout << res;
    return 0;
}