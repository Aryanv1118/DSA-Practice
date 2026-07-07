class Solution {
public:
    struct cmp{
        bool operator()(pair<int,string>& a,pair<int,string>& b){
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>q;
        vector<string> ans;
        for(string s:words){
            mp[s]++;
        }
        for(auto it:mp){
            q.push({it.second,it.first});
        }
        while(ans.size()!=k){
            string key = q.top().second;
            q.pop();
            ans.push_back(key);
        }
        return ans;
    }
};