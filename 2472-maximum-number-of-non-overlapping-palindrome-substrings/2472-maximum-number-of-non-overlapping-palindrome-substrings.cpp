class Solution {
public:
    vector<int>memo;
    vector<vector<bool>>pal;
    int dfs(string s,int k,int idx){
        if(idx >= s.length()){
            return 0;
        }
        if(memo[idx]!=-1)
            return memo[idx];
        int take = -1;
        int rt = -1;
        int ans;
        ans = dfs(s,k,idx+1);
        for(int i = idx+k-1;i<s.length();i++){
            if(pal[idx][i]){
                ans = max(ans,1+dfs(s,k,i+1));
                break;
            }
        }
        
        memo[idx] = ans;
        return memo[idx];
    }
    int maxPalindromes(string s, int k) {
        int n = s.length();
        memo.assign(s.length(),-1);
        pal.assign(n,vector<bool>(n,false));
        for(int i = 0;i<n;i++)
            pal[i][i] = true;
        for(int len = 2;len<=n;len++){
            for(int l = 0;l<=n-len;l++){
                int r = l+len-1;
                if(s[l] == s[r] &&(len == 2 || pal[l+1][r-1])){
                    pal[l][r] = true;
                }
            }
        }
        return dfs(s,k,0);
    }
};