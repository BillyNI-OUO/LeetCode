class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<string> stack;
        for (int i = 0; i < s.size(); ++i){
            if(s[i] == '(')stack.push_back("(");
            else if(s[i] == ')'){
                if(stack.back() != "("){
                    int temp = 0;
                    while(stack.back()!="("){
                        temp += stoi(stack.back());
                        stack.pop_back();
                    }
                    stack.pop_back();
                    stack.push_back(to_string(2*temp));
                }else{
                    stack.pop_back();
                    stack.push_back("1");
                }
            }        

        }
        int sum = 0;
        while(!stack.empty()){
            sum += stoi(stack.back());
            stack.pop_back();
        }
        return sum;
    }
};