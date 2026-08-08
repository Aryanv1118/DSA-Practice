class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int bottom = n-1;
        while(top<=bottom){
            int midc = top + (bottom-top)/2;
            if(target < matrix[midc][0]){
                bottom = midc-1;
            }
            else{
                top = midc+1;
            }
        }
        int row = top-1;
        if(row<0)
            return false;
        int l = 0;
        int r = m-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid]<target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return false;
    }
};