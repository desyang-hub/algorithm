#include "bits/stdc++.h"
using namespace std;


/**
 * @brief 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 */
class Solution {
    vector<vector<int>> result;
    vector<int> path;
public:
    vector<vector<string>> solveNQueens(int n) {
        backtrace(n);
        vector<vector<string>> res(result.size(), vector<string>(n, string(n, '.')));

        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < result[i].size(); ++j) {
                res[i][j][result[i][j]] = 'Q';
            }
        }

        return res;
    }

    void backtrace(int n) {
        if (path.size() == n) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (check(i)) {
                path.push_back(i);
                backtrace(n);
                path.pop_back();
            }
        }
    }

    bool check(int y) {
        int row = path.size();
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == y) {
                return false;
            }
            if (abs(row - i) == abs(y - path[i])) {
                return false;
            }
        }
        return true;
    }
};