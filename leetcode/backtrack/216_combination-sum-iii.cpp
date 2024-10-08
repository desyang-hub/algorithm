#include "bits/stdc++.h"
using namespace std;


/**
 * @brief 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
 * 
 */
class Solution {
    vector<vector<int>> paths;
    vector<int> path;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(1, k, n);
        
        return paths;
    }

    void backtrack(int startId, int k, int dis) {
        if (k == 0) {
            if (dis == 0) {
                paths.push_back(path);
            }
            return;
        }

        for (int i = startId; i <= min(dis, 9); ++i) {
            path.push_back(i);
            backtrack(i + 1, k - 1, dis - i);
            path.pop_back();
        }
    }
};