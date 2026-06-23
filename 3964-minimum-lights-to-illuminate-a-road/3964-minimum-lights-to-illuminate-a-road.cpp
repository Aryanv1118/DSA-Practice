class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<pair<int,int>> interval;
        for(int i = 0;i<n;i++){
            if(lights[i]>0){
                int L = max(0,i-lights[i]);
                int R = min(n-1,i+lights[i]);
                interval.push_back({L,R});
            }
        }
        sort(interval.begin(),interval.end());
        vector<pair<int,int>> merge;
        for(auto &p:interval){
            if(merge.empty() || p.first > merge.back().second+1){
                merge.push_back(p);
            }
            else{
                merge.back().second = max(merge.back().second,p.second);
            }
        }
        int ans = 0;
        int prev = -1;
        for(auto a:merge){
            int gap = a.first - prev - 1;
            if(gap > 0){
                ans += (gap+2)/3;
            }
            prev = a.second;
        }
        int lgp = n - prev - 1;
        if(lgp > 0){
            ans += (lgp+2)/3;
        }
        return ans;
    }
};