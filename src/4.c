double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	int left, right;
	left = (nums1Size+nums2Size+1)/2;
	right = (nums1Size+nums2Size+2)/2;
	return (findK(nums1, 0, nums2, 0, left, nums1Size, nums2Size) + findK(nums1, 0, nums2, 0, right, nums1Size, nums2Size)) / 2.0;
}

double findK(int* nums1, int i, int* nums2, int j, int k, int nums1Size, int nums2Size){
	if(i >= nums1Size)return nums2[j+k-1];
	if(j >= nums2Size)return nums1[i+k-1];
	if(k == 1)return nums1[i] < nums2[j] ? nums1[i] : nums2[j];
	int midVal1 = (i + k / 2 - 1 < nums1Size) ? nums1[i + k / 2 - 1] : INT_MAX;
    int midVal2 = (j + k / 2 - 1 < nums2Size) ? nums2[j + k / 2 - 1] : INT_MAX;
    if(midVal1 > midVal2)
    	return findK(nums1, i + k / 2 - 1, nums2, j, k / 2, nums1Size, nums2Size);
    else
    	return findK(nums1, i, nums2, j + k / 2 - 1, k / 2, nums1Size, nums2Size);
}
