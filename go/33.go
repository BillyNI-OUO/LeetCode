//Search in Rotated Sorted Array

package main

func search(nums []int, target int) int {
	left := 0
	right := len(nums) - 1
	var mid, max, maxIndex = 0, 0, 0
	max = nums[0]
	for left <= right {
		mid = (left + right) / 2
		if nums[mid] >= max {
			max = nums[mid]
			maxIndex = mid
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	if target >= nums[0] {
		left = 0
		right = maxIndex
	} else {
		left = maxIndex + 1
		right = len(nums) - 1
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

	return -1
}
