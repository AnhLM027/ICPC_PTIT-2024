#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int len_s;
    cin >> len_s;

    string S;
    cin >> S;

    long long dx[4] = { 0, 0, -1, 1 };
    long long dy[4] = { 1, -1, 0, 0 };

    long long total_dx = 0, total_dy = 0;

    for (char wind : S) {
        if (wind == 'U') total_dy++;
        if (wind == 'D') total_dy--;
        if (wind == 'L') total_dx--;
        if (wind == 'R') total_dx++;
    }

    long long left = 0, right = 1e18;

    while (left < right) {
        long long mid = (left + right) / 2;
        long long full_cycles = mid / len_s;
        long long remaining_steps = mid % len_s;

        long long curr_x = x1 + full_cycles * total_dx;
        long long curr_y = y1 + full_cycles * total_dy;

        for (int i = 0; i < remaining_steps; ++i) {
            if (S[i] == 'U') curr_y++;
            if (S[i] == 'D') curr_y--;
            if (S[i] == 'L') curr_x--;
            if (S[i] == 'R') curr_x++;
        }

        long long dist = abs(x2 - curr_x) + abs(y2 - curr_y);

        if (dist <= mid) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    if (right == 1e18) {
        cout << -1 << '\n';
    }
    else {
        cout << right << '\n';
    }

    return 0;
}