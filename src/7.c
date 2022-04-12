class Solution {
public:
    int reverse(int x) {
    long long i = 0;
    long long divisor = 1;
    while(i < 11){
    	if(abs(x)/divisor < 1)break;
    	divisor *= 10;
    	i ++;
    	}   
    long long ans = 0;
    for(long long j = i; j >= 0; j --){
    	
    	ans += (x/divisor%10)*power(i-j-1);
        divisor /= 10;
    }
    if(ans > 4294967296 || ans < -4294967296)return 0;
    return ans;
    }
    long long abs(long long x){
    	if(x < 0)return -1 * x;
    	return x;
    }
    long long power(long long x){
    	long long res = 1;
    	for(long long i = 0; i < x; i ++)
    		res *= 10;
    	return res;
    }
};