//Search Insert Position

package main

func searchInsert(nums []int, target int) int {
	left := 0
	right := len(nums) - 1
	mid := (left + right) / 2
	if len(nums) == 0 || nums[0] > target {
		return 0
	}
	for left <= right {
		mid = (left + right) / 2
		if nums[mid] == target {
			return mid
		} else if nums[mid] > target {
			right = mid - 1

		} else {
			left = mid + 1
		}

	}

	if nums[mid] > target {
		return mid
	}
	return mid + 1

}
