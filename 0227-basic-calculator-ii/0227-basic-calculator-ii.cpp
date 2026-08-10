class Solution {
public:
    int calculate(string s) {

    stack<int> num;

    int n = s.length();

    int temp = 0;

    char op = '+';

    for(int i = 0; i < n; i++) {

        if(isdigit(s[i])) {
            temp = temp * 10 + (s[i] - '0');
        }

        if((!isdigit(s[i]) && s[i] != ' ') || i == n-1) {

            if(op == '+') {
                num.push(temp);
            }

            else if(op == '-') {
                num.push(-temp);
            }

            else if(op == '*') {
                int a = num.top();
                num.pop();
                num.push(a * temp);
            }

            else if(op == '/') {
                int a = num.top();
                num.pop();
                num.push(a / temp);
            }

            op = s[i];
            temp = 0;
        }
    }

    int ans = 0;

    while(!num.empty()) {
        ans += num.top();
        num.pop();
    }

    return ans;
}
};