class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i ++){
            if(i < s.size()-1){

                
                if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M'))res -= 200;

                if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C'))res -= 20;

                if(s[i] == 'I' && (s[i+1] == 'X' || s[i+1] == 'V'))res -= 2;
            }
            if(s[i] == 'M')res += 1000;
            if(s[i] == 'D')res += 500;
            if(s[i] == 'C')res += 100;
            if(s[i] == 'L')res += 50;
            if(s[i] == 'X')res += 10;
            if(s[i] == 'V')res += 5;
            if(s[i] == 'I')res += 1;
        }
    return res;
    }
};