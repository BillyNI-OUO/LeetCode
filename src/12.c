class Solution {
public:
    string intToRoman(int num) {
        string res;
        for(int i = 0; i < num/1000; i ++)res += "M";
        
        if(num/100%10 == 9)res += "CM";
        else if(num/100%10 == 4)res += "CD";
        else {
            if(num/100%10 >= 5)res +=  "D";
            for(int i = 0; i < num/100%10%5; i ++)res += "C";
        }

        if(num/10%10 == 9)res += "XC";
        else if(num/10%10 == 4)res += "XL";
        else {
            if(num/10%10 >= 5)res += "L";
            for(int i = 0; i < num/100%10%5; i ++)res += "X";
        }

        if(num%10 == 9)res += "IX";
        else if(num%10 == 4)res += "IV";
        else {
            if(num%10 >= 5)res += "V";
            for(int i = 0; i < num%10%5; i ++)res += "I";
        }
    
        return res;
    }
};