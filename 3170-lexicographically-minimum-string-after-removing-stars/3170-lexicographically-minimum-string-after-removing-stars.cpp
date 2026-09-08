class Solution {
public:
    struct cmp{
        bool operator()(pair<char,int>&a,pair<char,int>&b){
            if(a.first!=b.first){
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,cmp>pq;
        vector<bool>deleted(s.length(),false);
        string ans;
        for(int i = 0;i<s.length();i++){
            if(s[i]!='*'){
                pq.push({s[i],i});
            }
            else{
                if(!pq.empty()){
                    auto[c,idx] = pq.top();
                    deleted[idx] = true;
                    pq.pop();
                }
            }
        }
        for(int i = 0;i<s.length();i++){
            if(s[i]!='*'&&!deleted[i])
                ans.push_back(s[i]);
        }
        return ans;
    }
};