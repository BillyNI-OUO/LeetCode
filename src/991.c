class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(target < startValue)return startValue - target;
        else return target % 2 == 0 ? 1+ brokenCalc(startValue, target/2) : 2 + brokenCalc(startValue, (target+1)/2);
    }
};