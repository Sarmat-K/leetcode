// Solution for problem 2130: Max twin sum of a Linked list

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
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            n++;
            temp = temp->next;
        }

        if(n % 2 != 0 )
            return -1;

        vector<int> val;
        temp = head;
        while(temp != nullptr){
            val.push_back(temp->val);
            temp = temp->next;
        }

        int max_sum = 0;
        for(int i = 0; i < n ; i++){
            int sum = val[i] + val[n-1-i];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }

    int pairSum_two_point(ListNode* head) {
        ListNode* slow = head , *fast = head;
        ListNode* prev = nullptr;

        while(fast != nullptr and fast->next != nullptr){
            fast = fast->next->next;
            ListNode* temp = slow.next;
            slow->next = prex;
            prev = slow;
            slow = temp;
        }

        int max_sum = 0;
        while (slow != nullptr){
            max_sum = max(max_sum , prev.val + slow.val);
            prev =prev.next;
            slow =slow.next;
        }

        return max_sum;

    }

};