//Valid Palindrome II

package main

func validPalidromeSmall(s string, left, right int) bool {
	for left < right {
		if s[left] != s[right] {
			return false
		}
		left++
		right--
	}
	return true
}

func validPalindrome(s string) bool {
	left := 0
	right := len(s) - 1

	for left < right {
		if s[left] == s[right] {
			left++
			right--
		} else {
			return validPalidromeSmall(s, left+1, right) || validPalidromeSmall(s, left, right-1)
		}
	}
	return true
}
