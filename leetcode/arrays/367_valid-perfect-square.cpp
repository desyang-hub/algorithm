#include "bits/stdc++.h"
using namespace std;

/**
 * @brief 给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。

不能使用任何内置的库函数，如  sqrt 。
 * 
 */

#define ll long long

class Solution {
public:
    bool isPerfectSquare(int num) {
        int res = mySqrt(num);
        return res * res == num;
    }

    int mySqrt(int x) {
        ll left = 0;
        ll right = x;
        ll mid;
        
        while (left <= right) {
            mid = (left + right) / 2;
            if (mid * mid < x) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left * left == x ? left : left - 1;
    }
};