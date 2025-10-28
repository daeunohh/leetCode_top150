class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for __ in range(9)] 
        cols = [set() for __ in range(9)] 
        subboxes = [[set() for __ in range(3)] for _ in range(3)]

        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue 
                if board[i][j] not in rows[i]:
                    rows[i].add(board[i][j])
                else:
                    # print(rows, cols, subboxes)
                    return False

                if board[i][j] not in cols[j]:
                    cols[j].add(board[i][j])
                else:
                    # print(rows, cols, subboxes)
                    return False

                if board[i][j] not in subboxes[i // 3][j // 3]:
                    subboxes[i // 3][j // 3].add(board[i][j])
                else:
                    # print(rows, cols, subboxes)
                    return False
        
        # print(rows, cols, subboxes)
        return True 