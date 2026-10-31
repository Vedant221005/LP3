
class NQueens:

    def __init__(self, n):
        self.n = n
        self.board = [["X" for _ in range(n)] for _ in range(n)]
        self.count = 0

    # Display chessboard
    def printBoard(self):
        for row in self.board:
            print(" ".join(row))
        print()

    # Check whether position is safe
    def isSafe(self, row, col):

        for i in range(row):
            if self.board[i][col] == "Q":
                return False

        # Upper-left diagonal
        i, j = row - 1, col - 1
        while i >= 0 and j >= 0:
            if self.board[i][j] == "Q":
                return False
            i -= 1
            j -= 1

        # Upper-right diagonal
        i, j = row - 1, col + 1
        while i >= 0 and j < self.n:
            if self.board[i][j] == "Q":
                return False
            i -= 1
            j += 1

        return True

    # Backtracking function
    def solve(self, row):

        if row == self.n:
            self.count += 1
            print("Solution", self.count)
            self.printBoard()
            return

        # Skip row if first Queen is already placed
        if "Q" in self.board[row]:
            self.solve(row + 1)
            return

        for col in range(self.n):

            if self.isSafe(row, col):

                self.board[row][col] = "Q"

                self.solve(row + 1)

                # Backtracking
                self.board[row][col] = "X"

    # Place first Queen
    def setFirstQueen(self):

        row = int(input("Enter row (1 to N): "))
        col = int(input("Enter column (1 to N): "))

        if row < 1 or row > self.n or col < 1 or col > self.n:
            print("Invalid position!")
            return False

        if not self.isSafe(row - 1, col - 1):
            print("Position is not safe!")
            return False

        self.board[row - 1][col - 1] = "Q"
        return True


# Main program
n = int(input("Enter size of chessboard: "))

if n <= 0:
    print("Invalid board size!")
else:
    queen = NQueens(n)

    if queen.setFirstQueen():
        queen.printBoard()
        queen.solve(0)

        if queen.count > 0:
            print("Solution exists.")
        else:
            print("Solution does not exist.")
