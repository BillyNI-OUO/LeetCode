//Longest Valid Parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() < 2)return 0;
        vector<int> stack;
        int max = 0;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '(')stack.push_back(-1);
            else{
                if(!stack.empty()){
                    int sum = 0;
                    int tag = 0;
                    while(!stack.empty()){
                        int temp = stack.back();
                        if(temp == -1){
                            stack.pop_back();
                            sum +=2;
                            stack.push_back(sum);
                            tag = 1;
                            break;
                        }
                        else if(temp == -2){
                            stack.push_back(sum);
                            stack.push_back(-2);
                            tag = 1;
                            break;
                        }
                        stack.pop_back();
                        sum += temp;
                    }
                    if(tag == 0){
                        stack.push_back(sum);
                        stack.push_back(-2);
                    }
                }
            }
        }
        int tempSum = 0;
        while(!stack.empty()){
            int temp = stack.back();
            if(temp != -1 && temp != -2){
                tempSum += temp;
            }else{
                max = max > tempSum ? max : tempSum;
                tempSum = 0;    
            }
            stack.pop_back();
        }
        max = max > tempSum ? max : tempSum;
        return max;

    }
};