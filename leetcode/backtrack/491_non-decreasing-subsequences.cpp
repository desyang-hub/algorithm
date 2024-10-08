#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。

数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
 * 
 */
class Solution {
    vector<vector<int>> result;
    vector<int> path;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrace(nums, 0);
        return result;
    }

    void backtrace(vector<int>& nums, int startId) {
        if (path.size() >= 2) {
            result.push_back(path);
        }
        if (startId == nums.size()) {
            return;
        }

        unordered_set<int> st;
        // 需要去重，而且不能进行排序
        for (int i = startId; i < nums.size(); ++i) {
            if (!st.empty() && st.count(nums[i])) {
                continue;
            }
            st.insert(nums[i]);
            if (path.empty() || path.back() <= nums[i]) {
                path.push_back(nums[i]);
                backtrace(nums, i + 1);
                path.pop_back();
            }
        }
    }
};