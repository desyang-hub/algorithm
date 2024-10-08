#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 
 * 
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix = vector(n, vector<int>(n, 0));

        int loop = (n + 1) / 2;
        int iter = 0;

        if (n % 2) {
            matrix[loop - 1][loop - 1] = n * n;
        }

        for (int i = 0; i < loop; ++i) {
            int left_top_x = i;
            int left_top_y = i;

            int right_top_x = n - i - 1;
            int right_top_y = i;

            int right_down_x = n - i - 1;
            int right_down_y = n - i - 1;

            int left_down_x = i;
            int left_down_y = n - i - 1;

            // 向右移动至right_top_x
            for (int j = left_top_x; j < right_top_x; ++j) {
                matrix[left_top_y][j] = ++iter;
            }
            // 向下移动至right_down_y
            for (int j = right_top_y; j < right_down_y; ++j) {
                matrix[j][right_top_x] = ++iter;
            }
            // 向左移动至left_down_x
            for (int j = right_down_x; j > left_down_x; --j) {
                matrix[right_down_y][j] = ++iter;
            }
            // 向上移动至left_top_y
            for (int j = left_down_y; j > left_top_y; --j) {
                matrix[j][left_down_x] = ++iter;
            }
        }

        return matrix;
    }
};

int main() {

    Solution slove;
    slove.generateMatrix(3);
    return 0;
}