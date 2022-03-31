int majorityElement(int* nums, int numsSize){
	int reg, cnt;
	reg = nums[0];
	cnt = 0;
	for(int i = 0; i < numsSize; i ++){
		if(reg == nums[i])cnt ++;
		else{
			if(cnt > 0)cnt --;
			else{
				reg = nums[i];
			}
		}
	}
	return reg;
}