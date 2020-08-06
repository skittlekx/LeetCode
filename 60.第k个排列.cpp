#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

// @lc code=start
class Solution {
public:
    int nN(int n){
        int res = 1;
        while(n){
            res *= n;
            n--;
        }
        return res;
    }
    string getPermutation(int n, int k) {
        string res = "";
        if(n==0)return res;
        vector<char> ch = {'1','2','3','4','5','6','7','8','9'};
        int _n = n;
        int nn = nN(--_n);
        while(1){
            if(k == 1){
                while(ch.size()){
                    if(ch.front() > n + '0')break;
                    res += ch.front();
                    ch.erase(ch.begin());
                }
                break;
            }
            int pos = 0;
            if(k%nn){
                pos = k / nn;
            }
            else{
                pos = k / nn - 1;
            }
            res += ch[pos];
            ch.erase(ch.begin() + pos);
            k %= nn;
            k = (k == 0 ? nn : k);
            nn = nN(--_n);
        }
        return res;
    }
};
// @lc code=end

int main(){
    Solution a;
    auto b = a.getPermutation(4,9);
    return 0;
}