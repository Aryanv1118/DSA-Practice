class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> rect;
        int count = 0;
        int maxArea = 0;
        int area = 0;
        int l,b;
        heights.push_back(0);
        for(int i = 0;i<=heights.size()-1;i++){
            while(!rect.empty() && heights[rect.top()] > heights[i]){
                int idx = rect.top();
                rect.pop();
                int r = i;
                if(!rect.empty())
                    l = rect.top();
                else
                    l = -1;
                int width = (r-l)-1;
                area = width*heights[idx];
                maxArea = max(area,maxArea);
            }
            rect.push(i);
        }
        return maxArea;
    }
};