#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * 
 */
class Solution {
    vector<vector<int>> result;
    vector<int> path;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> use(nums.size(), false);
        backtrace(nums, use);
        return result;
    }

    void backtrace(vector<int>& nums, vector<bool> &use) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        vector<int> used(30, false);

        for (int i = 0; i < nums.size(); ++i) {
            if (!use[i]) {
                // 去重逻辑，单轮不能使用相同的数字
                int idx = nums[i] + 10;
                if (used[idx]) {
                    continue;
                }
                used[idx] = true;

                use[i] = true;
                path.push_back(nums[i]);
                backtrace(nums, use);
                use[i] = false;
                path.pop_back();
            }
        }
    }
};