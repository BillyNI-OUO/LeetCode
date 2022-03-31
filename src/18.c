//4Sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4)return res;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size()-3; i ++){

        	if(i > 0 && nums[i] == nums[i-1])continue;

            vector<int>t2 = vector<int>(nums.begin()+i+1, nums.end());
        	vector<vector<int>> temp = threeSum(t2, target-nums[i]);

        	for(int j = 0; j < temp.size(); j ++){
        		temp[j].insert(temp[j].begin(),nums[i]);
        		res.push_back(temp[j]);
        	}
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int target){
    	vector<vector<int>> res;
    	for(int i = 0; i < nums.size()-2; i ++){

        	if(i > 0 && nums[i] == nums[i-1])continue;
        	int left = i + 1;
        	int right = nums.size()-1;
        	
        	while(left < right){
        		if((long)target == (long)nums[i] + nums[left] + nums[right]){
                   
                    res.push_back({nums[i], nums[left], nums[right]});
                    while(nums[right] == nums[right-1] && left < right)right --;
					while(nums[left] == nums[left+1] && left < right)left ++;
					
					left ++;
					right --;                    
                }
        		else if((long)target > (long)nums[i] + nums[left] + nums[right])
        			left ++;
        		else 
        			right --;
        	}
        }
        return res;
    }


};