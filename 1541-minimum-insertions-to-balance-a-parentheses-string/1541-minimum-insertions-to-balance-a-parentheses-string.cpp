class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        stack<int>st;
        int cl = 0;
        int ans = 0;
        int i;
        for(i = 0;i<n;i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(i+1<n && s[i+1] == ')'){
                    if(!st.empty()){
                        st.pop();
                    }
                    else{
                        ans++;
                    }
                    i++;
                }
                else{
                    if(!st.empty()){
                        st.pop();
                        ans++;
                    }
                    else{
                        ans += 2;
                    }
                }
            }
        }
        while(!st.empty()){
            ans += 2;
            st.pop();
        }
        return ans;
    }
};