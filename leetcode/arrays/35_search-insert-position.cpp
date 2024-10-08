#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
 * 
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        // 观察结束状态：当left==right时将进行最后一次执行，如果nums[mid] < target，left->left+1,也就是right+1，right右边一定大于等于target
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }

    int searchInsert1(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid;

        // 观察结束状态：当left+1=right时将进行最后一次执行，如果nums[mid] < target，left->left+1,也就是right，right一定大于等于target
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
};