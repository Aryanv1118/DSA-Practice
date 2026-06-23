class Solution {
public:
    int calculate(string s) {
        stack<int> op;
        long res = 0;
        int sign = 1;
        long current = 0;
        for(char x:s){
            if(isdigit(x)){
                current = current*10+(x-'0');
            }
            else if(x == '+'){
                res += sign*current;
                sign = 1;
                current = 0;
            }
            else if(x == '-'){
                res += sign*current;
                sign = -1;
                current = 0;
            }
            else if(x == '('){
                op.push(res);
                op.push(sign);
                sign = 1;
                res = 0;
            }else if(x == ')'){
                res += sign*current;
                current = 0;
                res = res*op.top();
                op.pop();
                res += op.top();
                op.pop();
            }
        }
        res += sign*current;
        return res;
    }
};