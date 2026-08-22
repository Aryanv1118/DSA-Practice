class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int bobsum = 0;
        int alicesum = 0;
        unordered_set<int>alice;
        for(int i = 0;i<aliceSizes.size();i++){
            alicesum += aliceSizes[i];
            alice.insert(aliceSizes[i]);
        }
        for(int x:bobSizes){
            bobsum += x;
        }
        int diff = (alicesum - bobsum)/2;
        int bbx;
        int abx;
        for(int x:bobSizes){
            if(alice.count(x+diff)){
                bbx = x;
                abx = x+diff;
                break;
            }
                
        }
        return {abx,bbx};
    }
};