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
        if(!head||k<1)
            return head;
        int i = 1,j = 0;
        ListNode* p = head,*q = head,*r = head;
        while (r->next)
        {
            ++i; //链表节点数
            r = r->next; // r在链表末尾
        }
        k %= i; //如果求模为0则不需要移动
        if (k==0)
            return head;
        k = i - k;//从第k个节点后断开
        for(j = 1; j < k; ++j)
        {
            p = p->next;
        }
        q = p->next;
        p->next = NULL;
        r->next = head;
        return q;
        
    }
};
