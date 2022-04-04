//Divide Two Integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int dividendL = abs(dividend);
        long long int divisorL = abs(divisor);
        long long int sign = (dividend >= 0 ^ divisor >= 0) ? -1: 1;
        long long int qutioent = 0;
        for(int i = 31; i >= 0; i --){
        	if((dividendL >> i) >= divisorL){
        		qutioent += (1LL << i);
        		dividendL -= (divisorL << i);
        	}
        }

        if(sign * qutioent > INT_MAX)
        	return INT_MAX;
        return sign*qutioent;
    }
};