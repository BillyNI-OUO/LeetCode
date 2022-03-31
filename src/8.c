class Solution {
public:
    int myAtoi(string s) {
    string ans = "";
    long long res = 0;
    int positive = 1;
    int tag = 1;
    if (s.size() == 0) return 0;
    int i = 0;
    while(i < s.size() && s[i] == ' ')i ++;
    for(; i < s.size(); i ++){
        if(s[i] == '+' && tag){
            tag = 0;
            continue;
        }
        if(s[i] == '-' && tag){
            tag = 0;
            positive = 0;
            continue;
        }
        if((int)s[i] > 57 || (int)s[i] < 48)break;
        tag = 0;
        ans += s[i];
    }
    if(ans.size() == 0)return 0;
    for(int i = ans.size()-1; i >= 0; i --){
        res += ((int)ans[i]-48)*power(ans.size()-1-i);
        if(res > 21474836470)break;
    }
    
    if(!positive)res *= -1;
    if(res > 2147483647)return 2147483647;
    if(res < -2147483648)return -2147483648;
    return res;
    }
    long long power (int i){
        long long res = 1;
        for(int j = 0; j < i; j ++){
            res *= 10;
            if(res > 2147483647)return 2147483647;
        }
        return res;
    }
}
;