//Valid Sudoku
package main

func isValidSudoku(board [][]byte) bool {

	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[i][j] != '.' {
				target := board[i][j]
				for k := j + 1; k < 9; k++ {
					if board[i][k] == target {
						return false
					}
				}
			}
		}
	}
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[j][i] != '.' {
				target := board[j][i]
				for k := j + 1; k < 9; k++ {
					if board[k][i] == target {
						return false
					}
				}
			}
		}
	}

	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[(i/3)*3+j/3][(i%3)*3+(j%3)] != '.' {
				target := board[(i/3)*3+j/3][(i%3)*3+(j%3)]
				for k := j + 1; k < 9; k++ {
					if board[(i/3)*3+k/3][(i%3)*3+(k%3)] == target {
						return false
					}
				}
			}
		}
	}
	return true
}
