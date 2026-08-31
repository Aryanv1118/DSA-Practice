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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int count = 0;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        vector<int>idx;
        while(curr){
            if(prev && curr->next && curr->val > prev->val && curr->val > curr->next->val){
                idx.push_back(count);
            }
            if(prev && curr->next && curr->val < prev->val && curr->val < curr->next->val){
                idx.push_back(count);
            }
            count++;
            prev = curr;
            curr = curr->next;
        }
        if(idx.size()<2)
            return {-1,-1};
        int mn = INT_MAX;
        for(int i = 1;i<idx.size();i++){
            mn = min(mn,idx[i]-idx[i-1]);
        }
        int mx = idx.back()-idx.front();
        return {mn,mx};
    }
};