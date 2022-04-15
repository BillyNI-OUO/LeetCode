// 1260. Shift 2D Grid
package main

func shiftGrid(grid [][]int, k int) [][]int {
	if l == 0 {
		return grid
	}
	m := len(grid)
	n := len(grid[0])
	var temp = grid[m-1][n-1]
	for i := m*n - 1; i > 0; i-- {
		grid[i/n][i%n] = grid[(i-1)/n][(i-1)%n]
	}
	grid[0][0] = temp
	return shiftGrid(grid, k-1)

}
