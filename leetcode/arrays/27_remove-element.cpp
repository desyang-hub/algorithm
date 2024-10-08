#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int assignId = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[assignId] = nums[i];
                ++assignId;
            }
        }

        return assignId;
    }
};