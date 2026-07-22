/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    int totalNodes(ListNode* head) {
        int total = 0;
        while(head != NULL) {
            total++;
            head = head->next;
        }

        return total;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int nodeNum = totalNodes(head) - n;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;

        while(temp && nodeNum > 0) {
            temp = temp->next;
            --nodeNum;
        }

        temp->next = temp->next->next;

        return dummy->next;
    }
};
