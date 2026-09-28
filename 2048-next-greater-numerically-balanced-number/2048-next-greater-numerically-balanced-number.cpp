class Solution {
public:
    bool isTrue(int n){
        int count[10] = {0};
        int temp = n;
        while(temp!=0){
            int dig = temp % 10;
            if(dig == 0)return false;
            temp /= 10;
            count[dig]++;
        }
        for(int i = 0;i<10;i++){
            if(count[i]>0 && count[i]!=i)return false;
        }    
        return true;
    }
    int nextBeautifulNumber(int n) {
        int ans = n+1;
        while(ans<1224444){
            if(isTrue(ans)){
                return ans;
            }
            ans++;
        }
        return 1224444;
    }
};