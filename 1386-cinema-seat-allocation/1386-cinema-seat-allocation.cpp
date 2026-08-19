class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int total = n << 1;
        unordered_map<int,tuple<bool,bool,bool>>mp;
        for(int i = 0;i<reservedSeats.size();i++){
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];

            if(seat >= 2 && seat <=5)get<0>(mp[row]) = true;
            if(seat >= 4 && seat <=7)get<1>(mp[row]) = true;
            if(seat >= 6 && seat <=9)get<2>(mp[row]) = true;
        }
        for(auto&[row,blocks]:mp){
            auto&[l,m,r] = blocks;
            if(l && r && m)total -= 2;
            else if(l || r || m)total--;
        }
        return total;
    }
};