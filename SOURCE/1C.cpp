#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int n, cnt;
int cot[100] = { 0 }, cheo1[100] = { 0 }, cheo2[100] = { 0 };

void Try(int i) {
    for (int j = 0; j < n; j++) {
        if (cot[j] == 0 && !cheo1[n + i - j] && !cheo2[i + j - 1]) {
            cot[j] = 1, cheo1[n + i - j] = 1, cheo2[i + j - 1] = 1;
            if (i == n) cnt++;
            else Try(i + 1);
            cot[j] = 0, cheo1[n + i - j] = 0, cheo2[i + j - 1] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cnt = 0;
    Try(1);
    cout << cnt;
    return 0;
}