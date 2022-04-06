//Find First and Last Position of Element in Sorted Array
package main

func searchRange(nums []int, target int) []int {
	left := 0
	right := len(nums) - 1
	var mid int = 0
	if len(nums) == 0 {
		return []int{
			-1,
			-1,
		}
	}
	for left <= right {
		mid = (left + right) / 2
		if nums[mid] == target {
			break
		} else if nums[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	left = mid
	right = mid
	tag := true
	for left >= 0 && right < len(nums) && tag {
		tag = false
		if left > 0 && nums[left-1] == target {
			left--
			tag = true
		}
		if right < len(nums)-1 && nums[right+1] == target {
			right++
			tag = true
		}
	}

	if nums[left] != target {
		left = -1
		right = -1
	}

	res := []int{
		left,
		right,
	}

	return res

}
