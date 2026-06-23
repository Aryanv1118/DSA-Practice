class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> op;
        int a,b;
        for(string x:tokens){
            if(x != "+" && x != "-" && x != "*" && x != "/"){
                op.push(stoi(x));
            }
            if(x == "+"){
                a = op.top();
                op.pop();
                b = op.top();
                op.pop();
                op.push(a+b);
            }
            if(x == "-"){
                a = op.top();
                op.pop();
                b = op.top();
                op.pop();
                op.push(b-a);
            }
            if(x == "*"){
                a = op.top();
                op.pop();
                b = op.top();
                op.pop();
                op.push(a*b);
            }
            if(x == "/"){
                a = op.top();
                op.pop();
                b = op.top();
                op.pop();
                op.push(b/a);
            }
        }
        return op.top();
    }
};