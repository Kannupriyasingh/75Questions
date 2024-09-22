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
/*

                      1 --> 2 --> 3 --> 4 --> 5
                 prev == NULL, curr == head (1), next == curr->next (2) {now we want to connect 2 by 1 instead of 3}
 first iteration ==>>  null <-- 1    2 --> 3 --> 4 --> 5   ===>>> null <-- 1 <-- 2 --> 3 --> 4 --> 5
    
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;   // null <-- 1    2 --> 3 --> 4 --> 5 {First Iteration}
            prev = curr;        
            curr = next;         //  null <-- 1 <-- 2 --> 3 --> 4 --> 5 {First Iteration}
        }
        return prev;
    }
};
