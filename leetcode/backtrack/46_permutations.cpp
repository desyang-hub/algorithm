#include "bits/stdc++.h"
using namespace std;


/**
 * @brief 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 */
class Solution {
    vector<vector<int>> result;
    vector<int> path;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> use(nums.size(), false);
        backtrace(nums, use);
        return result;
    }

    void backtrace(vector<int>& nums, vector<bool> &use) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!use[i]) {
                use[i] = true;
                path.push_back(nums[i]);
                backtrace(nums, use);
                use[i] = false;
                path.pop_back();
            }
        }
    }
};