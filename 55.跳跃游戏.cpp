#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)return true;
        int *res = new int [n];
        memset(res,0,n*sizeof(int));
        res[0] = 1;
        for(int i = 1;i < n; i++){
            int j = i-1;
            if(res[j] == 0)return false;
            while (j >= 0 && nums[j] + j < i)
            {
                j--;
            }
            if(j >= 0)res[i] = 1;

        }
        return res[n-1];
    }
};
// @lc code=end

int main(){
    Solution a;
    vector<int> input = {3,2,1,0,4};
    auto b = a.canJump(input);
    return 0;
}