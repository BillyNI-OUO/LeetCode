//Generate Parentheses

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string cur = "";
        dfs(n, 0, 0, cur);
        return res;
    }

    void dfs(int n, int left, int right, string cur){
        if(cur.size() == 2*n){
            res.push_back(cur);
            return ;
        }
        else
            if(left < n)
                dfs(n, left+1, right, cur+"(");
            if(right < left)
                dfs(n, left, right+1, cur+")");
    }
};