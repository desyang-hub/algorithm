#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 */
class Solution {
    string strs[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> result;
    string path;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return result;
        }
        backtrack(digits, 0);
        return result;
    }

    void backtrack(string &digits, int id) {
        if (id == digits.size()) {
            result.push_back(path);
            return;
        }

        int idx = digits[id] - '0';
        for (int i = 0; i < strs[idx].size(); ++i) {
            path.push_back(strs[idx][i]);
            backtrack(digits, id + 1);
            path.pop_back();
        }
    }
};