/*Given a node from a cyclic linked list which has been sorted, write a function to insert a value into the list such that it remains a cyclic sorted list. The given node can be any single node in the list. Return the inserted new node.

 Notice

3->5->1 is a cyclic list, so 3 is next node of 1.
3->5->1 is same with 5->1->3

Example
Given a list, and insert a value 4:
3->5->1
Return 5->1->3->4*/

//jiuzhang
class Solution {
public:
    /**
     * @param node a list node in the list
     * @param x an integer
     * @return the inserted new list node
     */
    ListNode* insert(ListNode* node, int x) {
        // Write your code here
        if (node == NULL) {
            node = new ListNode(x);
            node->next = node;
            return node;
        }

        ListNode* p = node;
        ListNode* prev = NULL;
        do {
            prev = p;
            p = p->next;
            if (x <= p->val && x >= prev->val) { 
                break;
            }
            if ((prev->val > p->val) && (x < p->val || x > prev->val)) {
                break;
            }
        } while (p != node);

        ListNode* newNode = new ListNode(x);
        newNode->next = p;
        prev->next = newNode;
        return newNode;
    }
};
