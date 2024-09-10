#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string sum(string num1, string num2) {
    string result;
    int carry = 0;
    int len1 = num1.size();
    int len2 = num2.size();
    int maxLen = max(len1, len2);
    string n1 = num1;
    string n2 = num2;
    while (n1.size() < maxLen) n1 = '0' + n1;
    while (n2.size() < maxLen) n2 = '0' + n2;
    for (int i = maxLen - 1; i >= 0; i--) {
        int sum = (n1[i] - '0') + (n2[i] - '0') + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }
    if (carry > 0) result += carry + '0';
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string Bell[100][100] = { "0" };
    Bell[1][1] = "1";
    string tmp = "1";
    for (int i = 1; i <= 50; i++) {
        Bell[i][1] = tmp;
        for (int j = 2; j <= i + 1; j++) {
            Bell[i][j] = sum(Bell[i - 1][j - 1], Bell[i][j - 1]);
        }
        tmp = Bell[i][i];
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << Bell[n][n] << endl;
    }
    return 0;
}