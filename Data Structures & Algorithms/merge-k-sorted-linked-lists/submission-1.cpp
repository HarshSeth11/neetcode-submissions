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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode(0);
        ListNode* ans = list3;

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                list3->next = list1;
                list1 = list1->next;
            }
            else{
                list3->next = list2;
                list2 = list2->next;
            }
            list3 = list3->next;
        }
        while(list1) {
            list3->next = list1;
            list1 = list1->next;
            list3 = list3->next;
        }
        while(list2) {
            list3->next = list2;
            list2 = list2->next;
            list3 = list3->next;
        }

        return ans->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;

        for(int i=1; i<lists.size(); i++) {
            lists[i] = mergeTwoLists(lists[i], lists[i-1]);
            // printList(lists[i]);
        }

        return lists[lists.size()-1];
    }
};
