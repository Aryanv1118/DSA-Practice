class Solution {
public:
    struct comp{
        bool operator()(pair<int,char>&a, pair<int,char>& b)const{
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char c: s)
            mp[c]++;
        priority_queue<pair<int,char>,vector<pair<int,char>>,comp> pq;
        for(auto &it:mp){
            pq.push({it.second,it.first});
        }
        string ans;
        while(!pq.empty()){
            auto[freq,c] = pq.top();
            ans += string(freq,c);
            pq.pop();
        }
        return ans;
    }
};