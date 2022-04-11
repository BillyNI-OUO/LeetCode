class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> res;
        for(int i = 0; i < ops.size(); i ++){
            if(ops[i] == "C"){
                res.pop();
            }else if(ops[i] == "D"){
                int num = res.back();
                res.push_back(num*2);
            }else if(ops[i] == "+"){
                res.push_back(res[res.size()-1] + res[res.size()-2]);
            }else{
                res.push_back(stoi(ops[i]));
            }

        }
        int sum = 0;
        for(auto a:res){
            sum += a;
        }   
        return sum;
    }
};