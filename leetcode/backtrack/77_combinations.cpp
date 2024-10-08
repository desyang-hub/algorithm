#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。
 * 
 */
class Solution {
    vector<vector<int>> paths;
    vector<int> path;
public:
    vector<vector<int>> combine(int n, int k) {

        backtrack(1, n, k);

        return paths;
    }

    void backtrack(int id, int n, int k) {
        // 判断出口
        if (k == 0) {
            paths.push_back(path);
            return;
        }

        for (int i = id; i <= n; ++i) {
            path.push_back(i);
            backtrack(i + 1, n, k - 1);
            path.pop_back();
        }
    }
};