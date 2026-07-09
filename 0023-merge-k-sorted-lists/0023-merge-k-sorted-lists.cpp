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
    ListNode* sorting(ListNode* list1,ListNode* list2){
        ListNode* head = new ListNode(0) ;
        ListNode* temp;
        temp = head;
        while(list1 && list2){
            if(list1->val > list2->val){
                temp->next = list2;
                list2 = list2->next;
            }
            else{
                temp->next = list1;
                list1 = list1->next; 
            }
            temp = temp->next;
        }
        while(list1){
            temp->next = list1;
            list1 = list1->next;
            temp = temp->next; 
        }
        while(list2){
            temp->next = list2;
            list2 = list2->next;
            temp = temp->next ;
        }
        head = head->next;
        return head;
    }
    ListNode* sortklist(vector<ListNode*>& lists,int start,int end){
        vector<ListNode*>temp;
        if(lists.size() == 0){
            return nullptr;
        }
        if(lists.size() == 1){
            return lists[0];
        }
        int i = start;
        int j = end;
        while(i<j){
            temp.push_back(sorting(lists[i],lists[j]));
            i++;
            j--;
        }
        if(i == j)
            temp.push_back(lists[j]);
        int n = temp.size();
        return sortklist(temp,0,n-1);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return sortklist(lists,0,n-1);
    }
};