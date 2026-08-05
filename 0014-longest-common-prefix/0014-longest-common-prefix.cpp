class TrieNode{
    public:
        vector<TrieNode*> next;
        bool end;
        TrieNode(){
            next.assign(26,nullptr);
            end = false;
        };
};
class Solution {
public:
    int ans = 0;
    void insert(string& s,TrieNode* root){
        TrieNode* curr = root;
        for(char c:s){
            if(curr->next[c-'a'] == nullptr)
                curr->next[c-'a'] = new TrieNode();
            curr = curr->next[c-'a'];
        }
        curr->end = true;
    }
    int chcount(TrieNode* root,int &idx){
        int count = 0;
        idx = -1;
        for(int i = 0;i<26;i++){
            if(root->next[i]!=nullptr){
                count++;
                idx = i;
            }
        }
        return count;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        TrieNode* root = new TrieNode();
        for(auto &s:strs){
            insert(s,root);
        }
        TrieNode* temp = root;
        while(true){
            int idx;
            int count = chcount(temp,idx);
            if(count!=1 || temp->end){
                break;
            }
            ans += 'a'+idx;
            temp = temp->next[idx];
        }
        return ans;
    }
};