#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。
 * 
 */
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = move_back(s);
        int j = move_back(t);

        if (i != j) {
            return false;
        }

        for (int k = 0; k < i; ++k) {
            if (s[k] != t[k]) {
                return false;
            }
        }

        return true;
    }

    int move_back(string &s) {
        int assignId = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '#') {
                if (assignId > 0) {
                    --assignId;
                }
            }
            else {
                s[assignId] = s[i];
                ++assignId;
            }
        }

        return assignId;
    }
};