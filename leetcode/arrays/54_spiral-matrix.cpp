#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;

        int loop = (min(m, n) + 1) / 2;
        
        for (int i = 0; i < loop; ++i) {
            int lt_x = i;
            int lt_y = i;

            int rt_x = n - i - 1;
            int rt_y = i;

            int rb_x = n - i - 1;
            int rb_y = m - i - 1;

            int lb_x = i;
            int lb_y = m - i - 1;

            // 一行或者一列的时候特殊判断即可
            if (lt_y == rb_y) {
                for (int j = lt_x; j <= rb_x; ++j) {
                    res.push_back(matrix[lt_y][j]);
                }
                continue;
            }

            if (lt_x == rb_x) {
                for (int j = lt_y; j <= rb_y; ++j) {
                    res.push_back(matrix[j][lt_x]);
                }
                continue;
            }
            

            for (int j = lt_x; j < rt_x; ++j) {
                res.push_back(matrix[lt_y][j]);
            }

            for (int j = rt_y; j < rb_y; ++j) {
                res.push_back(matrix[j][rt_x]);
            }

            for (int j = rb_x; j > lb_x; --j) {
                res.push_back(matrix[rb_y][j]);
            }

            for (int j = lb_y; j > lt_y; --j) {
                res.push_back(matrix[j][lb_x]);
            }
        }

        return res;
    }
};