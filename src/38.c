//Count and Say

class Solution {
public:
    string countAndSay(int n) {
        
        if(n == 1)return "1";
        if(n == 0)return "";
        string s = "1";
        return helper(n-1, s);
    }

    string helper(int n, string s){
        if(n == 0)return s;
        string res = "";
        
        int i = 0;
        while(i < s.size()){
            int cnt = 1;
            for(; i < s.size()-1; i ++){
                if(s[i] != s[i+1])break;
                cnt ++;
            }
            res += to_string(cnt)+ s[i++];
        }
        return helper(n-1, res);
    }   
};