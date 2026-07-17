class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        vector<vector<char>> buckets(n+1);
        unordered_map<char,int> mp;
        for(char c: s)
            mp[c]++;
        for(auto &it:mp)
            buckets[it.second].push_back(it.first);
        string ans;
        
        for(int i = n;i>=1;i--){
            sort(buckets[i].begin(),buckets[i].end());
            for(char c:buckets[i])
                ans.append(i,c);
        }
        return ans;
    }
};