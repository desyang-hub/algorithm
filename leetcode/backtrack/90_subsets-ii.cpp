#include "bits/stdc++.h"
using namespace std;


/**
 * @brief 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 
子集
（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 * 
 */
class Solution {
    vector<vector<int>> result;
    vector<int> path;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrace(nums, 0);
        return result;
    }

    void backtrace(vector<int>& nums, int startId) {
        result.push_back(path);
        if (startId == nums.size()) {
            return;
        }

        for (int i = startId; i < nums.size(); ++i) {
            if (i != startId && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            backtrace(nums, i + 1);
            path.pop_back();
        }
    }
};