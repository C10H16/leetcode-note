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
            ++i; //����ڵ���
            r = r->next; // r������ĩβ
        }
        k %= i; //�����ģΪ0����Ҫ�ƶ�
        if (k==0)
            return head;
        k = i - k;//�ӵ�k���ڵ��Ͽ�
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
