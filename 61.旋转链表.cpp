#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        if(k == 0)return head;
        int lc = 1;
        auto lpe = head;
        while(lpe->next){
            lpe = lpe->next;
            lc++;
        }
        lpe->next = head;

        int p2 = lc - k%lc - 1;
        auto lp1 = head;
        while(p2--)lp1 = lp1->next;
        
        auto lp2 = lp1->next;
        lp1->next = NULL;
        return lp2;
    }
};
// @lc code=end


