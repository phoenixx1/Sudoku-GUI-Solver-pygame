//author @Nishant
/*
Below is implementation of how to solve sudoku using Backtracking
*/
#include<bits/stdc++.h>
using namespace std;

#define N 9

vector<int> find_empty(vector<vector<int>> grid){
    vector<int> cell{-1, -1};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 0){
                cell[0] = i;
                cell[1] = j;
                return cell;
            }
        }
    }
    return cell;
}

bool valid(vector<vector<int>> grid, int num, vector<int> cell){
    // row
    for(int i = 0; i < N; i++){
        if(grid[cell[0]][i] == num && cell[1] != i){
            return false;
        }
    }

    // col
    for(int i = 0; i < N; i++){
        if(grid[i][cell[1]] == num && cell[0] != i){
            return false;
        }
    }

    //grid
    int x = cell[0] - cell[0] % 3, y = cell[1] - cell[1] % 3;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i + x][j + y] == num && i != cell[0] && j != cell[1]){
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<int>> &grid){
    vector<int> find = find_empty(grid);
    int row = find[0], col = find[1];

    if(find[0] == -1){
        return true;
    }

    for(int i = 1; i < 10; i++){
        if(valid(grid, i, find)){
            grid[row][col] = i;

            // to check if the assigned value is still valid in sudoku
            if(solve(grid)){
                return true;
            }
            // if not then we will set it zero and check again
            // for the previous value assigned in the sudoku
            grid[row][col] = 0;
        }
    }
    return false;
}

void printSolution(vector<vector<int>> grid){
    for(int i = 0; i < N; i++){
        if(i % 3 == 0 && i != 0){
            cout << "- - - - - - - - - - - - - " << endl;
        }
        for(int j = 0; j < N; j++){
            if(j % 3 == 0 && j != 0){
                cout << " | ";
            }
            if(j == 8){
                cout << grid[i][j] << endl;
            }else{
                cout << grid[i][j] << " ";
            }
        }
    }
}

int main(){
    vector<vector<int>> grid{   {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                                {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                                {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                                {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                                {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                                {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                                {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    
    if(solve(grid)){
        printSolution(grid);
    }else{
        cout << "NO SOLUTION EXISTS" << endl;
    }
    return 0;
}