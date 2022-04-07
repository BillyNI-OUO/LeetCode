//Combination Sum

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return helper(candidates, target, 0);
        
    }

    vector<vector<int>> helper(vector<int> candidates, int target, int index) {
        vector<vector<int>> res;
        if(target < 1)return res;
        if(index >= candidates.size())return res;
        for(int i = index; i < candidates.size(); i ++){
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            int first = candidates[i];
            vector<vector<int>> next;
            if(first == target){
                vector<int> element;
                element.push_back(first);
                res.push_back(element);
                return res;
            }
            next = helper(candidates, target-first, i+1);
            for(int j = 0; j < next.size(); j ++){
                next[j].insert(next[j].begin(), first);  
                res.push_back(next[j]);
            }

        }

        return res;
    }

};