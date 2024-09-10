#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOD(i,a,b) for(int i=a;i<=b;i++)
#define FODV(i,a,b) for(int i=a;i>=b;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORV(i,a,b) for(int i=a;i>b;i--)

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int a[1005][1005];
        FOD(i, 1, n) {
            FOD(j, 1, m) cin >> a[i][j];
        }
        int s = 0;
        FOD(i, 1, n) {
            FOD(j, 1, m) {
                if (a[i][j] > 0) {
                    for (int z = 1; z <= a[i][j]; z++) {
                        s += 4;
                        if (z == 1) s++;
                        if (z == a[i][j]) s++;
                        if (i + 1 <= n && a[i + 1][j] >= z) s--;
                        if (i - 1 >= 1 && a[i - 1][j] >= z) s--;
                        if (j + 1 <= m && a[i][j + 1] >= z) s--;
                        if (j - 1 >= 1 && a[i][j - 1] >= z) s--;
                    }
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}