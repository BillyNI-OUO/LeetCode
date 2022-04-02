//Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int* count = new int [201];
        for(int i = 0; i < 201; i ++)
        	count[i] = 0;
        for(int i = 0; i < nums.size(); i ++){
        	count[nums[i]+100]++;
        }
        int cnt = 0;
        for(int i = 0; i < 201; i ++){
        	if(count[i] > 0)
        		nums[cnt++] = i-100;
        }
        return cnt;


    }
};