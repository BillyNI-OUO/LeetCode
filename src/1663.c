class Solution {
public:
    string getSmallestString(int n, int k) {
    int *resIndex = new int[n];    
    for(int i = 0; i < n; i ++)
        resIndex[i] = 1;
    int temp = n;
    for(int i = n-1; i >= 0; i --){
        if(k-temp <= 0)break;
        int Index = k-temp > 25 ? 25 : k-temp;
        resIndex[i] += Index;
        temp += Index;
    }
    string res = "";
    for(int i = 0; i < n; i ++)
        res.push_back((char)(resIndex[i]+96));

    return res;
    }
};