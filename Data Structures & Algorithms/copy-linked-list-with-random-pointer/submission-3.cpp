/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        Node* temp = head;

        while(temp) {
            Node* next = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = next;
            temp = next;
        }


        temp = head;

        while(temp) {
            temp->next->random = temp->random? temp->random->next : NULL;
            temp = temp->next->next;
        }

        temp = head;
        Node* ans = temp->next;

        Node* first = temp;
        Node* second = ans;

        while(first && second) {
            first->next = first->next? first->next->next : NULL;
            second->next = second->next? second->next->next : NULL;

            first = first->next;
            second = second->next;
        }

        return ans;
    }
};
