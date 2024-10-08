#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 给定一个含有 n 个正整数的数组和一个正整数 target 。找出该数组中满足其总和大于等于 target 的长度最小的子数组[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 * 
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int id = 0;
        int sum = 0;
        int minLen = -1;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            if (sum >= target) {
                while (sum >= target && id <= i) {
                    sum -= nums[id];
                    ++id;
                }

                
                if (minLen == -1) {
                    minLen = i - id + 2;
                }
                else {
                    minLen = min(i - id + 2, minLen);
                }
            }
        }

        return max(0, minLen);

    }
};