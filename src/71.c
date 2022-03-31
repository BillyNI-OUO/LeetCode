class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        int i = 0;
        while(i path.size()){
            while(path[i] == '/' && i < path.size())i ++;
            int start = i;
            if(i == path.size())break;
            while(path[i] != '/' && i < path.size())i ++;
            int end = i - 1;
            string s = path.substring(start, end - start + 1);
            if(s == ".."){
                if(!stack.empty())stack.pop_back();
            }else if(s != '.'){
                stack.push_back(s);
            }
        }
        if(stack.empty())return '/';
        string ans;
        for(int i = 0; i < stack.size(); i ++){
            ans += '/' + stack[i];
        }
        return ans;
    }
};