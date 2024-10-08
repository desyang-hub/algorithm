#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 * 
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> exist(nums.size() + 2, false);
        for (auto &i : nums) {
            if (i <= nums.size() && i > 0) {
                exist[i] = true;
            }
        }

        for (int i = 1; i < exist.size(); ++i) {
            if (!exist[i]) {
                return i;
            }
        }

        return -1;
    }
};