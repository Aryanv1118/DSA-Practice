class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        int temp = n;
        for(int i = 0;i<s;i++){
            if(flowerbed[i] == 1)
                continue;
            bool leftempty = (i == 0 || flowerbed[i-1] == 0);
            bool rightempty = (i == s-1 || flowerbed[i+1] == 0);
            if(leftempty && rightempty){
                temp--;
                flowerbed[i] = 1;
            }
            if(temp == 0)
                break; 
        }
        return temp <= 0;
    }
};