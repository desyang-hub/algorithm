#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 * 
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        // 当列表为空
        if (nums.empty()) {
            return {-1, -1};
        }

        int i = lower_bound(nums, target);
        int j = upper_bound(nums, target);

        // 全部元素均小于target
        if (i >= nums.size() || nums[i] != target) {
            return {-1, -1};
        }

        return {i, j - 1};
    }

    int lower_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid;

        while (left < right) {
            mid = (left + right) / 2;
            
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }

    int upper_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid;

        while (left < right) {
            mid = (left + right) / 2;
            
            if (nums[mid] <= target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
};
