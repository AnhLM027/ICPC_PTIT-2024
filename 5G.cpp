#include <bits/stdc++.h>
using namespace std;

// Hàm tính diện tích nước có thể giữ lại với một mảng chiều cao nhất định
int calculateWater(const vector<int>& heights) {
    int n = heights.size();
    if (n == 0) return 0;

    vector<int> left_max(n), right_max(n);
    left_max[0] = heights[0];
    for (int i = 1; i < n; ++i) {
        left_max[i] = max(left_max[i - 1], heights[i]);
    }

    right_max[n - 1] = heights[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        right_max[i] = max(right_max[i + 1], heights[i]);
    }

    int water = 0;
    for (int i = 0; i < n; ++i) {
        water += min(left_max[i], right_max[i]) - heights[i];
    }

    return water;
}

// Hàm đệ quy với cắt tỉa nhánh để tối ưu hóa
void tryChanges(int k, vector<int>& heights, int index, int n, int& maxWater) {
    if (k < 0) return;

    // Tính diện tích nước với chiều cao hiện tại
    maxWater = max(maxWater, calculateWater(heights));

    // Nếu không còn thay đổi, kết thúc
    if (k == 0) return;

    // Thử thay đổi chiều cao cột đá từ chỉ số hiện tại trở đi
    for (int i = index; i < n; ++i) {
        ++heights[i];
        tryChanges(k - 1, heights, i, n, maxWater); // Cắt tỉa nhánh
        --heights[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    int maxWater = calculateWater(heights);
    tryChanges(k, heights, 0, n, maxWater);

    cout << maxWater << endl;

    return 0;
}