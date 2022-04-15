//  First Missing Positive
package main

func firstMissingPositive(nums []int) int {
	n := len(nums)

	for i := 0; i < n; i++ {
		for nums[i] > 0 && nums[i] != i+1 && nums[i] <= n {
			temp := nums[i]
			nums[i] = nums[nums[i]-1]
			nums[temp-1] = temp
		}
	}

	for i := 0; i < n; i++ {

		if nums[i] != i+1 {
			return i + 1
		}
	}
	return n + 1
}
