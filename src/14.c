class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*暴力硬解
        int index = 0;
        int minlen = 201;

        for(int i = 0; i < strs.size(); i ++)
            minlen = minlen > strs[i].size() ? strs[i].size() : minlen;
        
        for(; index < minlen; index ++){
            bool tag = true;
            char common = strs[0][index];
            for(int i = 1; i < strs.size(); i ++){
                if(strs[i][index] != common){
                    tag = false;
                    break;
                }

            }
            if(!tag)break;
        }

        return strs[0].substr(0, index);
        */

        int comlen = 201, minStr = 0;
        for(int i = 0; i < strs.size(); i ++){
            if(comlen > strs[i].size()){
                comlen = strs[i].size();
                minStr = i;
            }
        }

        string common;
        common = strs[minStr];

        for(int i = 0; i < strs.size(); i ++){
            for(int j = 0; j < comlen; j ++){
                if(common[j] != strs[i][j]){
                    comlen = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, comlen);

    }
};

/*一直去更新Common prefix 的長度，可以減少比對相同前字串的次數，當字串數多的時候可能比暴力解快一點(LeetCode 上的測資快一倍)*/
