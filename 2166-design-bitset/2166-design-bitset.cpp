class Bitset {
public:
    vector<int>bits;
    vector<int>toggle;
    Bitset(int size) {
        bits.assign(size,0);
        toggle.assign(size,1);
    }
    int sum = 0;
    void fix(int idx) { 
        if(bits[idx] == 0){
            bits[idx] = 1;
            toggle[idx] = 0;
            sum++;
        }
    }
    
    void unfix(int idx) {
        if(bits[idx] == 1){
            bits[idx] = 0;
            toggle[idx] = 1;
            sum--;
        }
    }
    
    void flip() {
        bits.swap(toggle);
        sum = bits.size()-sum;
    }
    
    bool all() {
        return sum == bits.size();
    }
    
    bool one() {
        return sum > 0;
    }
    
    int count() {
        return sum;
    }
    
    string toString() {
        string s;
        for(int i = 0;i<bits.size();i++){
            s += to_string(bits[i]);
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */