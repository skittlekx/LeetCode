#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        if(n < 2)return intervals;
        sort(intervals.begin(),intervals.end()
            ,[](vector<int> a, vector<int> b){
                return a[0] < b[0];
            });
        auto temp = intervals[0];
        for(int i = 1;i<n;i++){
            if(intervals[i][0] <= temp[1])
                temp[1] = max(temp[1],intervals[i][1]);
            else{
                res.push_back(temp);
                temp = intervals[i];
            }
        }
        res.push_back(temp);
        return res;
    }
};
// @lc code=end

