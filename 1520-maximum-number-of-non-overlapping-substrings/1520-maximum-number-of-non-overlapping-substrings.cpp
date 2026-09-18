class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            return a.second < b.second;
        }
    };
    vector<string> maxNumOfSubstrings(string s) {
        vector<string>ans;
        int n = s.length();
        vector<int>start(26,-1);
        vector<int>end(26,-1);
        for(int i = 0;i<n;i++){
            if(start[s[i]-'a']==-1){
                start[s[i]-'a'] = i;
            }
        }
        for(int i = n-1;i>=0;i--){
            if(end[s[i]-'a']==-1){
                end[s[i]-'a'] = i;
            }
        }
        vector<pair<int,int>>intervals;
        for(int c = 0;c<26;c++){
            if(start[c]==-1)
                continue;
            int l = start[c];
            int r = end[c];
            bool valid = true;
            for(int k = l;k<=r;k++){
                int d = s[k]-'a';
                if(start[d]<l){
                    valid = false;
                    break;
                }
                r = max(r,end[d]);
            }
            if(valid)
                intervals.push_back({l,r});   
        }
        sort(intervals.begin(),intervals.end(),cmp());
        int prev = -1;
        for(auto[left,right]:intervals){
            if(left>prev){
                ans.push_back(s.substr(left,right-left+1));
                prev = right;
            }
        }
        return ans;
    }
};