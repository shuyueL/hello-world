/*Merge two sorted (ascending) linked lists and return it as a new sorted list. 
The new sorted list should be made by splicing together the nodes of the two lists and sorted in ascending order.
Example
Given 1->3->8->11->15->null, 2->null , return 1->2->3->8->11->15->null.
*/

//jiuzhang

class Solution {
public:
    /*
    题意：合并两个有序链表
    模拟一轮归并排序
    */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tmp = dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tmp->next = l1;
                l1 = l1->next;
            } else {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        if (l1 != NULL) tmp->next = l1;
        else tmp->next = l2;
        return dummy->next;
    }
};
