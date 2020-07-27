#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        //5555 
        if(x < 0)return false;
        if(x == 0)return true;
        long long y = 0;
        int len = (int)log10(x)+1;
        long long xn = x;
        while(xn){
            int xy = xn % 10;
            y += xy * pow(10,--len);
            xn /= 10;
        }
        return x == y;
    }
};
// @lc code=end
int main(){
    Solution so;
    so.isPalindrome(101);
    return 0;
}
