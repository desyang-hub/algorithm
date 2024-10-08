#include "bits/stdc++.h"
using namespace std;


/**
 * @brief 你正在维护一个项目，该项目有 n 个方法，编号从 0 到 n - 1。

给你两个整数 n 和 k，以及一个二维整数数组 invocations，其中 invocations[i] = [ai, bi] 表示方法 ai 调用了方法 bi。

已知如果方法 k 存在一个已知的 bug。那么方法 k 以及它直接或间接调用的任何方法都被视为 可疑方法 ，我们需要从项目中移除这些方法。

只有当一组方法没有被这组之外的任何方法调用时，这组方法才能被移除。

返回一个数组，包含移除所有 可疑方法 后剩下的所有方法。你可以以任意顺序返回答案。如果无法移除 所有 可疑方法，则 不 移除任何方法。
 * 
 */
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> path(n);
        vector<vector<int>> path_(n);
        vector<int> result;
        for (int i = 0; i < invocations.size(); ++i) {
            vector<int> &p = invocations[i];
            path[p[0]].push_back(p[1]);
            path_[p[1]].push_back(p[0]);
        }

        // 存在可疑的方法
        unordered_set<int> st;
        st.insert(k);

        queue<int> q;
        q.push(k);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < path[cur].size(); ++i) {
                int next = path[cur][i];
                if (st.count(next)) {
                    continue;
                }
                q.push(next);
                st.insert(next);
            }
        }

        if (st.size() == n) {
            return {};
        }

        int num_st = st.size();

        for (auto &item : st) {
            q.push(item);
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < path_[cur].size(); ++i) {
                int next = path_[cur][i];
                if (st.count(next)) {
                    continue;
                }
                q.push(next);
                st.insert(next);
            }
        }

        

        if (st.size() != num_st) {
            for (int i = 0; i < n; ++i) {
                result.push_back(i);
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                if (st.count(i) == 0) {
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};