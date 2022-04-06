//Container With Most Water
package main

func maxArea(height []int) int {
	left := 0
	right := len(height) - 1
	var max, tall, area = 0, 0, 0
	for left < right {

		if height[left] > height[right] {
			tall = height[right]
		} else {
			tall = height[left]
		}
		area = tall * (right - left)

		if max < area {
			max = area
		}

		if tall == height[left] {
			left++
		} else {
			right--
		}
	}
	return max
}
