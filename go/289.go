//Game of Life

package main

func check(board [][]int, x, y int) int {
	sum := 0
	m := len(board)
	n := len(board[0])
	for i := -1; i < 2; i++ {
		for j := -1; j < 2; j++ {
			if x+i >= 0 && x+i < m && y+j >= 0 && y+j < n {
				sum += board[x+i][y+j]
			}
		}
	}
	return sum
}

func gameOfLife(board [][]int) {
	m := len(board)
	n := len(board[0])
	temp := make([][]int, m)
	for i := 0; i < m; i++ {
		temp[i] = make([]int, n)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] == 1 {
				count := check(board, i, j)
				switch count {
				case 0, 1, 2:
					temp[i][j] = 0
				case 3, 4:
					temp[i][j] = 1
				default:
					temp[i][j] = 0
				}
			} else {
				count := check(board, i, j)
				if count == 3 {
					temp[i][j] = 1
				} else {
					temp[i][j] = 0
				}
			}
		}
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			board[i][j] = temp[i][j]
		}
	}

}
