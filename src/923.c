//3Sum With Multiplicity

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        long long int cnt = 0;
        for(int i = 0; i < arr.size()-1; i ++){
        	int left = i+1;
        	int right = arr.size()-1;
        	while(left < right){
        		if(arr[i] + arr[left] + arr[right] == target){

	                    int temp = 1;
	        			int leftTemp = 1;
	        			int rightTemp = 1;
	 					if(arr[left] == arr[right]){
	 						cnt+=(right-left+1)*(right-left)/2;
	 					}
	                    while(right > left && arr[right] == arr[right-1]){
	                        right--;
	                        rightTemp++;
	                    }
	                    while(left < right && arr[left] == arr[left+1]){
	                        left++;
	                        leftTemp++;
	                    }
                        if(arr[left] != arr[right])
							cnt += leftTemp*rightTemp;
	                    left++;
	                    right--;
	                    

        		}else if(arr[i] + arr[left] + arr[right] > target){
        			right --;
        		}else{
        			left ++;
        		}
        	}
        }
        return cnt%1000000007;
    }
};