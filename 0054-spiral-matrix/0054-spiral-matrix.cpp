class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> so;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int left = 0;
        int right = n-1;
        int bottom = m-1;
        while(so.size()!=m*n){
            for(int i = left;i<=right;i++){
                so.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top;i<=bottom;i++){
                so.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i = right;i>=left;i--){
                    so.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            if(left<=right){
                for(int i = bottom;i>=top;i--){
                    so.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return so;
    }
};