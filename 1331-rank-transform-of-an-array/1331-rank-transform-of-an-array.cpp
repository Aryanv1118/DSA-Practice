class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> mp;
        int i = 1;
        for(auto x:temp){
            if(!mp.count(x))
                mp[x] = i++;
        }
        for(auto& num:arr){
            num = mp[num];
        }
        return arr;
    }
};