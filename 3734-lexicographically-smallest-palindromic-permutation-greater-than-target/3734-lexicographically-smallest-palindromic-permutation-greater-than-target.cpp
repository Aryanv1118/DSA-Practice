class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int>freq(26);
        int n = target.length();
        for(int i =0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        char c;
        int odd_count = 0;
        for(int i = 0;i<26;i++){
            if(freq[i]%2 == 1){
                c = i+'a';
                odd_count++;
            }
            freq[i] /= 2;
        }
        if(odd_count > 1){
            return "";
        }
        string ans = "";
        string thalf = target.substr(0,n/2);
        int idx = 0;
        while(idx<thalf.size() && freq[thalf[idx]-'a']>0){
            freq[thalf[idx]-'a']--;
            idx++;
        }
        if (idx < thalf.size()) {
            for (int i = thalf[idx] - 'a' + 1; i < 26; i++) {
                if (freq[i] > 0){
                    ans = thalf.substr(0, idx);
                    ans.push_back(i+'a');
                    freq[i]--;

                    for(int k = 0;k<26;k++){
                        ans.append(freq[k],k+'a');
                    }
                    string rev = ans;
                    reverse(rev.begin(),rev.end());
                    string pal;
                    if(n%2 == 1){
                        pal = ans + string(1,c) + rev;
                    }
                    else{
                        pal = ans+rev;
                    }
                    if(pal > target)
                        return pal;    
                }
            }              
        }
        if(n%2 == 1 && idx == thalf.size()){
            string pal;
            if(c > target[n/2]){
                ans = thalf;
                string rev = ans;
                reverse(rev.begin(),rev.end());
                pal =  ans + string(1,c) + rev;
            }
            else if(c == target[n/2]){
                ans = thalf;
                string rev = ans;
                reverse(rev.begin(),rev.end());
                pal =  ans + string(1,c) + rev;
            }
            if(pal > target)
                return pal;
        }
        else if(n%2 == 0 && idx == thalf.size()){
            ans = thalf;
            string rev = ans;
            reverse(rev.begin(),rev.end());
            string pal = ans+rev;
            if(pal > target)
                return pal;
        }
        for(int j = idx-1;j>=0;j--){
            freq[thalf[j]-'a']++;
            for(int i = thalf[j]-'a'+1;i<26;i++){
                if(freq[i] > 0){
                    ans = thalf.substr(0,j);
                    ans.push_back(i+'a');
                    freq[i]--;
                    for(int k = 0;k<26;k++){
                        ans.append(freq[k],k+'a');
                    }
                    string rev = ans;
                    reverse(rev.begin(),rev.end());
                    string pal;
                    if(n%2 == 1){
                        pal = ans + string(1,c) + rev;
                    }
                    else{
                        pal = ans+rev;
                    }
                    if(pal > target)
                        return pal;
                }
            }
        }
        return "";
    }
};