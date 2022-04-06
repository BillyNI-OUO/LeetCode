//37. Sudoku Solver

package main

func checkSudoku(board [][]byte, x, y int) bool {
	target := board[x][y]
	cnt = 0
	for i := 0; i < 9; i++ {
		if board[x][i] == target {
			cnt++
		}
		if board[i][y] == target {
			cnt++
		}
		if board[x/3*3+i/3][y/3*3+i%3] == target {
			cnt++
		}
	}

	if cnt != 3 {
		return false
	}
	return true
}

func helper(board [][]byte, x, y int) bool {
	if x == 9 {
		return true
	}
	if y == 9 {
		return helper(board, x+1, 0)
	}
	if board[x][y] != '.' {
		return helper(board, x, y+1)
	}

	for nums := 1; nums < 10; nums++ {
		board[x][y] = byte(nums + 48)
		if !checkSudoku(board, x*9+y) {
			board[x][y] = '.'
			continue
		}
		if helper(board, x, y+1) {
			return true
		}
		board[x][y] = '.'
	}
	return false
}

func solveSudoku(board [][]byte) {
	helper(board, 0, 0)

}
