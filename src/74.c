//Search a 2D Matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int hleft = 0, hright = matrix.size()-1;
        if(matrix.size() == 0)return false;
        int n = matrix[0].size();
        int m = hright;
        int hmid = (hleft + hright) / 2;;
        
        while(hleft < hright){
            hmid = (hleft + hright) / 2;
            if(target == matrix[hmid][n-1])return true;
            if(target > matrix[hmid][n-1])hleft = hmid + 1;
            else hright = hmid;
        }
        
        if(target > matrix[hmid][n-1])hmid += 1;
        if(hmid > m)return false;
        if(matrix[hmid][n-1] == target)return true;
        
        int left = 0, right = n-1;
        int mid = (left + right) / 2;
        if(matrix[hmid][mid] == target)return true;
        while(left < right){
            mid = (left + right) / 2;
            if(target == matrix[hmid][mid])return true;
            if(target > matrix[hmid][mid])left = mid + 1;
            else right = mid;
        }
        return false;
    }
};