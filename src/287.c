//Find the Duplicate Number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size();
        int mid = 0;
        int size = nums.size();
        while(left < right){
            mid = (left + right) / 2;
            int cnt = 0;
            int cnt_1 = 0;
            for(int i = 0; i < nums.size(); i ++){
                if(nums[i] > mid)cnt++;
                if(nums[i] == mid)cnt_1 ++;
            }
            if(cnt_1 > 1)return mid;
            if(cnt > size/2){
                left = mid;
                size = cnt;
            }
            else if(cnt < size/2){
                right = mid;
                size = cnt;
            }else return mid;
            
        }
        return mid;
    }
};