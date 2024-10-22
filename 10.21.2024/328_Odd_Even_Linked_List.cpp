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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)  
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* head_even = even;
        ListNode* temp = head->next->next;
        int i = 1;        
        while(temp != nullptr){
            if(i % 2 !=0){
                odd->next = temp;
                odd = odd->next;
            }else {
                even->next = temp;
                even = even->next;
            }
            temp = temp->next;
            i++;
        }
        even->next = nullptr;
        odd->next = head_even;
        return head;
    }
};