# Leetcode 21 合并两个有序链表
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
```
示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```

## 分析
只要比较两个链表的每个节点，将较小的节点加入新链表即可。当其中一个链表到达末尾，只需要将另一个链表的剩余部分加入新链表即可。

## 代码
```c++
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* re = new ListNode(0);
        ListNode *p1 = l1, *p2 = l2, *p3 = re;
        while (p1 && p2)
        {
            if(p1->val <= p2->val)
            {
                p3->next = p1;
                //p3->next = new ListNode(p1->val);
                //不需要重新开辟空间
                p3 = p3->next;
                p1 = p1->next;
            }
            else
            {
                p3->next = p2;
                //p3->next = new ListNode(p2->val);
                p3 = p3->next;
                p2 = p2->next;
            }
        }
        if(p1)
        {
            p3->next = p1;
        }
        if(p2)
        {
            p3->next = p2;
        }
        return re->next;
    }
};
```
