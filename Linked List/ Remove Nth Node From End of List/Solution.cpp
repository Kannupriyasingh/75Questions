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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;
        //Finding the length of linked list
        while(temp) {length++; temp = temp->next;}
    
        int index = 1;
        ListNode* curr = head;
        ListNode* curr_head = curr;
        while(curr) {
            index++;
            if((length - n) == 0) {  //if we have to remove the first element
                curr_head = curr->next;
                break;
            }
            else if(index == (length - n + 1)) {  //it will work for all the remaining cases
                curr->next = curr->next->next;
            }
            curr = curr->next;
        } 
        return curr_head;
    }
};
