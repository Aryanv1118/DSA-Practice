class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x_clo = max(x1,min(x2,xCenter));
        int y_clo = max(y1,min(y2,yCenter));
        int dist = (x_clo - xCenter)*(x_clo - xCenter)+(y_clo-yCenter)*(y_clo-yCenter);
        return dist <= radius*radius;
    }
};