class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        if(x == 1)
            return 1;
        int low = 0;
        int high = x;
        while(low<high){
            int mid = low+(high-low)/2;
            if((long long)mid*mid == x)
                return mid;
            else if((long long)mid*mid < x){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low-1;
    }
};