class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int max = 0;
        while(left < right){
            int temp = min(height[left], height[right])*(right - left);
            if(temp > max)max = temp;
            if(height[left] < height[right])left++;
            else right --;
        }
        return max;
    }
};