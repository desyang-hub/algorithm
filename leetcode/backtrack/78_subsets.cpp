#include "bits/stdc++.h"
using namespace std;


/**
 * @brief 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的
子集
（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 * 
 */
class Solution {
    vector<vector<int>> result;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
            path.push_back(nums[i]);
            backtrace(nums, i + 1);
            path.pop_back();
        }
    }
};