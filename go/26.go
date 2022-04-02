//Remove Duplicates from Sorted Array

package main

func removeDuplicates(nums []int) int {
	var count [201]int
	for i := 0; i < 201; i++ {
		count[i] = 0
	}
	for i := 0; i < len(nums); i++ {
		count[nums[i]+100]++
	}
	var cnt = 0
	for i := 0; i < 201; i++ {
		if count[i] > 0 {
			nums[cnt] = i - 100
			cnt++
		}
	}
	return cnt

}
