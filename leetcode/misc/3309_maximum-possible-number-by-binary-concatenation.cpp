#include "bits/stdc++.h"
using namespace std;


/**
 * @brief 给你一个长度为 3 的整数数组 nums。

现以某种顺序 连接 数组 nums 中所有元素的 二进制表示 ，请你返回可以由这种方法形成的 最大 数值。

注意 任何数字的二进制表示 不含 前导零。
 * 
 */
class Solution {
    string convertBinaryStr(int n) {
        string out;
        while (n) {
            out.push_back('0' + n % 2);
            n /= 2;
        }
        reverse(out.begin(), out.end());
        return out;
    }

    int DicimalConversion(string binStr, int radix) {
        int r = 1;
        int result = 0;
        for (int i = binStr.size() - 1; i >= 0; --i) {
            result += r * (binStr[i] - '0');
            r *= radix;
        }
        return result;
    }

    static bool cmp(string &a, string &b) {
        return (a + b) > (b + a);
    }

public:
    int maxGoodNumber(vector<int>& nums) {
        vector<string> strs(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            strs[i] = convertBinaryStr(nums[i]);
        }
        sort(strs.begin(), strs.end(), cmp);
        string str;
        for (int i = 0; i < strs.size(); ++i) {
            str += strs[i];
        }
        return DicimalConversion(str, 2);
    }
};