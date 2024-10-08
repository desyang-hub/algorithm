#include "bits/stdc++.h"
using namespace std;


/**
 * @brief 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 * 
 */
class Solution {
public:
    string minWindow(string s, string t) {
        // 使用滑动窗口
        unordered_map<char, int> dict;
        unordered_map<char, int> dict_s;
        for (char &ch : t) {
            ++dict[ch];
        }
        
        int preId = 0;
        string res = "";

        for (int i = 0; i < s.size(); ++i) {
            if (dict.count(s[i])) {
                ++dict_s[s[i]];

                // 判断条件是否满足
                if (check(dict_s, dict)) {
                    // 尽可能缩小区间
                    while (preId < i) {
                        if (dict.count(s[preId]) == 0) {
                            ++preId;
                        }
                        else {
                            if (dict[s[preId]] < dict_s[s[preId]]) {
                                --dict_s[s[preId]];
                                ++preId;
                            }
                            else {
                                break;
                            }
                        }
                    }
                    // 找到临界点
                    string str = s.substr(preId, i - preId + 1);
                    if (res.empty()) {
                        res = str;
                    }
                    else {
                        res = res.size() < str.size() ? res : str;
                    }
                }
            }
        }

        return res;
    }

    // 校验条件是否满足
    // 必须用引用，不然会发生大量的拷贝构造，花费大量时间
    bool check(unordered_map<char, int> &dict_s, unordered_map<char, int> &dict_t) {
        for (auto &pair_instance : dict_t) {
            if (dict_s[pair_instance.first] < pair_instance.second) {
                return false;
            }
        }
        
        return true;
    }
};