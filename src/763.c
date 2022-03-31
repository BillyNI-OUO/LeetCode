class Solution {
public:
    vector<int> partitionLabels(string s) {
        int start[26], last[26];
        for(int i = 0; i < 26; i ++){
            start[i] = -1;
            last[i] = -1;
        }
        for(int i = 0; i < s.size(); i ++){
            int index = (int)s[i]-97;
            if(start[index] != -1)last[index] = i;
            if(start[index] == -1)start[index] = i;

        }
    }
};