#include "bits/stdc++.h"
using namespace std;


/**
 * @brief 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。
 * 
 */
class Solution {
    vector<vector<int>> result;
    vector<int> path;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return result;
    }

    void backtrack(vector<int>& candidates, int startId, int target) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = startId; i < candidates.size(); ++i) {
            // 排序，去重的关键是，相同的元素每轮只能够使用一次
            if (i != startId && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] <= target) {
                path.push_back(candidates[i]);
                backtrack(candidates, i + 1, target - candidates[i]);
                path.pop_back();
            }
        }
    }
};