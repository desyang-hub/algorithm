#include "bits/stdc++.h"
using namespace std;


/**
 * @brief 在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。
 * 
 */
class Solution {
public:
    #define ll long long
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<ll> pre_sum(gas.size());
        vector<ll> suf_sum(gas.size());
        for (int i = 0; i < gas.size(); ++i) {
            gas[i] -= cost[i];
            pre_sum[i] = gas[i];
            suf_sum[i] = gas[i];
        }
        for (int i = 1; i < pre_sum.size(); ++i) {
            pre_sum[i] += pre_sum[i - 1];
        }
        for (int i = suf_sum.size() - 2; i >= 0; --i) {
            suf_sum[i] += suf_sum[i + 1];
        }

        auto min_value_iter = min_element(pre_sum.begin(), pre_sum.end());
        auto min_value_index = distance(pre_sum.begin(), min_value_iter);

        if (*min_value_iter >= 0) {
            return 0;
        }

        // 最小值是最末尾的数字，那么直接无解
        if (min_value_index+1 == pre_sum.size()) {
            return -1;
        }

        for (int i = min_value_index+1; i < pre_sum.size(); ++i) {
            if (pre_sum[i] - pre_sum[min_value_index] < 0) {
                return -1;
            }
        }

        if (-(*min_value_iter) <= suf_sum[min_value_index+1]) {
            return min_value_index + 1;
        }
        
        return -1;
    }
};