class Solution {
public:
    int largestInteger(int num) {
        int nums[10];

        int cnt = 0;
        long long int i = 1;
        bool tag = true;
        while(num >= i){
            if(tag){
                nums[cnt++] = num/i%10;
            }
            i *= 10;
        }

        for(int j = cnt-1; j >= 0; j --){
            if(nums[j]%2 == 0){
                for(int k = j-1; k >= 0; k --){
                    if(nums[k] % 2 == 0 && nums[j] < nums[k]){
                        int temp = nums[j];
                        nums[j] = nums[k];
                        nums[k] = temp;
                    }
                }
            }else{
                for(int k = j-1; k >= 0; k --){
                    if(nums[k] % 2 == 1 && nums[j] < nums[k]){
                        int temp = nums[j];
                        nums[j] = nums[k];
                        nums[k] = temp;
                    }
                }
            }
        }
        long long int res = 0;
        for(int j = cnt-1; j >= 0; j --){
            res *= 10;
            res += nums[j];
            
        }
        return res;
    }
};