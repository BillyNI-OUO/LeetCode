class Solution {
public:
    string minRemoveToMakeValid(string s) {
     vector<string> stack;
     vector<int> nouse;
     int i = 0;
     int cnt = 0;
     int start = 0;
     while(i < s.size()){
        if(s[i] != '(' && s[i] != ')'){
        start = i;
        while(i < s.size() && s[i] != '(' && s[i] != ')')i ++;
        int end = i - 1;
        string temp = s.substr(start, end - start + 1);
        stack.push_back(temp);
        cnt ++;
    }
        if(s[i] == '('){
            stack.push_back("(");
            nouse.push_back(cnt);
            cnt ++;
            i++;
        }
        if(s[i] == ')'){
            if(!nouse.empty()){
                nouse.pop_back();
                stack.push_back(")");
                cnt ++;
            }
            i ++;
        }
     }
     while(!nouse.empty()){
        int index = nouse.back();
        nouse.pop_back();
        stack.erase(stack.begin() + index);
     }
     string ans;
     for(int i = 0; i < stack.size(); i ++){
        ans += stack[i];
     }
     return ans;
    
    }
};