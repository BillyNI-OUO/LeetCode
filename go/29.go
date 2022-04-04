//Divide Two Integers

package main

import "math"

func divide(dividend int, divisor int) int {
	var dividendL int64 = int64(math.Abs(float64(dividend)))
	var divisorL int64 = int64(math.Abs(float64(divisor)))
	var sign int64
	if (dividend >= 0) != (divisor >= 0) {
		sign = -1
	} else {
		sign = 1
	}
	var qutioent int64
	for i := 31; i >= 0; i-- {
		if dividendL>>i >= divisorL {
			qutioent += 1 << i
			dividendL -= divisorL << i
		}
	}
	if sign*qutioent >= math.MaxInt32 {
		return math.MaxInt32
	}
	return int(sign * qutioent)
}
