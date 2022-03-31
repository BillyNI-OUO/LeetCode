class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stack;
        int pushLen, popLen;
        pushLen = pushed.size();
        popLen = popped.size();
        int i, j = 0;
        while(i < pushed.size() && j < popped.size()){
            if(!stack.empty() && stack.back() == popped[j]){
                stack.pop_back();
                j ++;
                continue;
            }
            stack.push_back(pushed[i++]);
        }
        while(j < popped.size()){
             if(!stack.empty() && stack.back() == popped[j]){
                stack.pop_back();
                j ++;
                continue;
            }else return false;
        }
        return true;
    }
};