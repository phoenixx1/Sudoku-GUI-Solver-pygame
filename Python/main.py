# author @Nishant

# Below is implementation of how to solve sudoku using Backtracking

def find_empty(grid):
    for i in range(9):
        for j in range(9):
            if grid[i][j] == 0:
                return (i, j)
    return None

def valid(grid, num, cell):
    # row
    for i in range(9):
        if(grid[cell[0]][i] == num and cell[1] != i):
            return False
    #col
    for i in range(9):
        if(grid[i][cell[1]] == num and cell[0] != i):
            return False
    
    #box
    x = cell[0] - cell[0] % 3
    y = cell[1] - cell[1] % 3

    for i in range(3):
        for j in range(3):
            if(grid[i + x][j + y] == num and i != cell[0] and j != cell[1]):
                return False
    return True

def solve(grid):
    find = find_empty(grid)
    if not find:
        return True
    else:
        row = find[0]
        col = find[1]
    
    for i in range(1, 10):
        if(valid(grid, i, find)):
            grid[row][col] = i
            # to check if the assigned value is still valid in sudoku
            if solve(grid):
                return True
            # if not then we will set it zero and check again
            # for the previous value assigned in the sudoku
            grid[row][col] = 0
    return False

def printSolution(grid):
    for i in range(9):
        if(i % 3 == 0 and i != 0):
            print("- - - - - - - - - - - - - ")
        for j in range(9):
            if(j % 3 == 0 and j!= 0):
                print(" | ", end = "")
            if j == 8:
                print(grid[i][j])
            else:
                print(str(grid[i][j]) + " ", end = "")

grid = [[3, 0, 6, 5, 0, 8, 4, 0, 0], 
        [5, 2, 0, 0, 0, 0, 0, 0, 0], 
        [0, 8, 7, 0, 0, 0, 0, 3, 1], 
        [0, 0, 3, 0, 1, 0, 0, 8, 0], 
        [9, 0, 0, 8, 6, 3, 0, 0, 5], 
        [0, 5, 0, 0, 9, 0, 6, 0, 0], 
        [1, 3, 0, 0, 0, 0, 2, 5, 0], 
        [0, 0, 0, 0, 0, 0, 0, 7, 4], 
        [0, 0, 5, 2, 0, 6, 3, 0, 0]]
if solve(grid):
    printSolution(grid)
else:
    print("NO SOLUTION EXISTS")