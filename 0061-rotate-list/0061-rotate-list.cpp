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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    int len(ListNode* head){
        ListNode* curr = head;
        int ans = 0;
        while(curr){
            ans++;
            curr = curr->next;
    }
    return ans;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        int n = len(head);
        if(k%n == 0){
            return head;
        }
        int m = k%n ;
        head = reverse(head);
        ListNode* temp1 = head;
        ListNode* curr = head;
        int count = 1;
        while(count!=m){
            curr = curr->next;
            count++;
        }
        ListNode* temp2 = curr->next;
        curr->next = nullptr;
        temp1 = reverse(temp1);
        ListNode* it = temp1;
        while(it->next){
            it = it->next;
        }
        it->next = reverse(temp2);
        return temp1;
    }
};