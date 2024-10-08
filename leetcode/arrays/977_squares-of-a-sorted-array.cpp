#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 * 
 */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        vector<int> res;

        while (left <= right) {
            if (abs(nums[left]) < abs(nums[right])) {
                res.push_back(nums[right] * nums[right]);
                --right;
            }
            else {
                res.push_back(nums[left] * nums[left]);
                ++left;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};