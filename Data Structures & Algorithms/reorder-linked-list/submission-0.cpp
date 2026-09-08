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
    void reorderList(ListNode* head) {
        // seperate
        ListNode* p1 = head;
        ListNode* p2 = head;

        while(p2 && p2->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }

        p2 = p1->next;
        p1->next = nullptr;
        p1 = head;

        // reverse
        ListNode* dummy = nullptr;
        ListNode* temp = nullptr;

        while(p2){
            temp = p2;
            p2 = p2->next;

            temp->next = dummy;
            dummy = temp;
        }
        p2 = dummy;

        // merge
        while(p1 && p2){
            ListNode* t1 = p1->next;
            ListNode* t2 = p2->next;
            
            p1->next = p2;
            p2->next = t1;

            p1 = t1;
            p2 = t2;
        }
    }
};
