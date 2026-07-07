class Solution {
public:
    static bool cmp(string& a,string& b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        string s;
        vector<string> temp;
        for(auto num:nums){
            temp.push_back(to_string(num));
        }
        sort(temp.begin(),temp.end(),cmp);
        if(temp[0] == "0")
            return "0";
        for(auto x:temp){
            s += x;
        }
        return s;
    }
};