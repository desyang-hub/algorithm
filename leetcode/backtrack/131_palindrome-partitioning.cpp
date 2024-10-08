#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 
回文串
 。返回 s 所有可能的分割方案。
 * 
 */
class Solution {
    vector<vector<string>> result;
    vector<string> path;
public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return result;
    }

    /**
     * @brief 判断是否回文
     */
    bool check(string &s, int i, int j) {
        while (s[i] == s[j] && i < j) {
            ++i;
            --j;
        }
        return i >= j;
    }

    void backtrack(string &s, int startId) {
        if (startId == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = startId; i < s.size(); ++i) {
            if (check(s, startId, i)) {
                path.push_back(s.substr(startId, i - startId + 1));
                backtrack(s, i + 1);
                path.pop_back();
            }
        }
    }
};