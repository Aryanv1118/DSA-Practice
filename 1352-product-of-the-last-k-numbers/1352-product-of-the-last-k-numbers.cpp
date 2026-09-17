class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    vector<int>prod;
    void add(int num) {
        prod.push_back(num);
    }
    
    int getProduct(int k) {
        int ans = 1;
        int n = prod.size();
        for(int i = n-k;i<n;i++){
            ans *= prod[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */