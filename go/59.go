//59. Spiral Matrix II

package main

func generateMatrix(n int) [][]int {
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = make([]int, n)
	}
	var way = 0
	var cnt = 1
	var x, y = -1, 0
	index := 1
	for i := n; i > 0; i-- {
		for ; cnt < 2; cnt++ {
			for j := 0; j < i; j++ {
				switch way {
				case 0:
					x++
				case 1:
					y++
				case 2:
					x--
				case 3:
					y--
				}
				res[y][x] = index
				index++

			}
			way = (way + 1) % 4

		}
		cnt = 0

	}
	return res
}
