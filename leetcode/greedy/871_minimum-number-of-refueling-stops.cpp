#include "bits/stdc++.h"
using namespace std;


/**
 * @brief 汽车从起点出发驶向目的地，该目的地位于出发位置东面 target 英里处。

沿途有加油站，用数组 stations 表示。其中 stations[i] = [positioni, fueli] 表示第 i 个加油站位于出发位置东面 positioni 英里处，并且有 fueli 升汽油。

假设汽车油箱的容量是无限的，其中最初有 startFuel 升燃料。它每行驶 1 英里就会用掉 1 升汽油。当汽车到达加油站时，它可能停下来加油，将所有汽油从加油站转移到汽车中。

为了到达目的地，汽车所必要的最低加油次数是多少？如果无法到达目的地，则返回 -1 。

注意：如果汽车到达加油站时剩余燃料为 0，它仍然可以在那里加油。如果汽车到达目的地时剩余燃料为 0，仍然认为它已经到达目的地。
 * 
 */

// 解题关键，优先队列、可达范围内加最多的油
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int cur = 0; // 可抵达的位置
        int gas = startFuel;

        priority_queue<int> pq;
        int gas_cnt = 0; // 加油次数

        while (cur + gas < target) {
            // 将可抵达范围内的油加入到优先队列中
            for (int i = 0; i < stations.size(); ++i) {
                int pos = stations[i][0];
                int num_gas = stations[i][1];
                // 避免重复添加同一个加油站
                if (pos > cur && pos <= cur + gas) {
                    pq.push(num_gas);
                }
            }

            // 如果没有油可加，直接退出
            if (pq.empty()) {
                break;
            }

            // 否则加最多的油
            ++gas_cnt; // 加一次油
            cur += gas;
            gas = pq.top();
            pq.pop();
        }

        if (cur + gas >= target) {
            return gas_cnt;
        }

        return -1;
    }
};