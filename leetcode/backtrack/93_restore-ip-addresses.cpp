#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案
 * 
 */
class Solution {
    vector<string> result;
    string path;
public:
    vector<string> restoreIpAddresses(string s) {
        backtrace(s, 0, 4);
        return result;
    }

    void backtrace(string &s, int startId, int num) {
        if (startId == s.size() || num == 0) {
            if (num == 0 && startId == s.size()) {
                result.push_back(path);
            }
            return;
        }

        string tmp = path;

        for (int i = startId; i < min(int(s.size()), startId + 3); ++i) {
            if (i - 1 == startId && s[startId] == '0') {
                break;
            }
            string str = s.substr(startId, i - startId + 1);
            if (check(str)) {
                if (path.empty()) {
                    path += str;
                }
                else {
                    path.push_back('.');
                    path += str;
                }
                backtrace(s, i + 1, num - 1);
                path = tmp;
            }
        }
    }

    bool check(string &s) {
        if (s.size() < 3) {
            return true;
        }
        return stoi(s) <= 255;
    }
};