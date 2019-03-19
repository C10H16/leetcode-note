// 203-ÒÆ³ıÁ´±íÔªËØ 

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p;
        p = head;
        if (!p)
            return head;
        while(p->val == val)
        {
            head = p->next;
            p = head;
            if (!p)
                return head;
        }
        while(p->next)
        {
            if (p->next->val==val)
                p->next = p->next->next;
            else 
                p = p->next;
        }
        return head;  
        
    }
};
