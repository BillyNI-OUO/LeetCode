class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty())return res;
        unordered_map<int, int> numCount;

        vector<int> sortVector = nums;
        sort(sortVector.begin(), sortVector.end()); 
        for(int i = 0; i < sortVector.size(); i ++){

            numCount[sortVector[i]]++;
        }
        /*
        for(h = numCount.begin(); h != numCount.end(); h ++){
            int a, b, c;
            a = h->first;
            h->second --;
            for(it = h; it != numCount.end(); it ++){
                if(it->second == 0)continue;
                b = it->first;
                it->second --;
                c = 0 - a -b;
                if(numCount.find(c) == numCount.end() || numCount.find(c)->second == 0){
                    it->second++;
                    continue;
                }
                vector<int> temp = {a, b, c};
                
                res.push_back(temp);
                temp.clear();
                it->second++;
            }
            h->second++;
        }
        */
        int last_a = sortVector[0]+1;
        int last_b;
        for(int i = 0; i < sortVector.size(); i ++){
           int a, b, c;
           a = sortVector[i];

           if(last_a == a)continue;
           last_a = a;
           numCount[a]--;
           
           if(i+1 < sortVector.size())
                last_b = sortVector[i+1]+1;
           
           for(int j = i+1; j < sortVector.size(); j ++){
                b = sortVector[j];
                
                if(numCount[b] == 0 || last_b == b)
                    continue;
                last_b = b;
                
                numCount[b]--;
                c = 0 - a - b;
                if(c < b){
                    numCount[b]++;
                    break;
                }
                if(numCount.find(c) == numCount.end() || numCount.find(c)->second == 0){
                        numCount[b]++;
                        continue;
                    }

                res.push_back(vector<int> {a, b, c});
                numCount[b]++;
           }
           numCount[a]++;

        }
        
        return res;

    }
};