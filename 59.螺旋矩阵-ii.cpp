#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    void getNextPos(int& i,int& j,int& dict){
        switch (dict)
        {
        case 0:
            j += 1;
            break;
        case 1:
            i += 1;
            break;
        case 2:
            j -= 1;
            break;
        case 3:
            i -=1;
            break;
        default:
            break;
        }
    }
    void getNextPos(vector<vector<int>>& data,int& i,int& j,int& dict){
        int prei = i;
        int prej = j;
        getNextPos(prei,prej,dict);
        int n = data.size();
        if(prei < 0 || prei >= n || prej < 0 || prej >= n || data[prei][prej]){
            dict = (dict + 1)%4;
        }
        
        getNextPos(i,j,dict);
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        for(int i = 0; i<n; i++){
            vector<int> temp(n,0);
            res.push_back(temp);
        }
        int _i = 0,_j = 0;
        int dict = 0;
        for(int a = 1;a<=n*n;a++){
            res[_i][_j] = a;
            getNextPos(res,_i,_j,dict);
        }
        return res;
    }
};
// @lc code=end
int main(){
    Solution a;
    auto b = a.generateMatrix(3);
    return 0;
}

