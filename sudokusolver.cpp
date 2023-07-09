#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int sudoku[9][9],int row,int col, int n){
    
    for(int i=0;i<9;i++){
        if(sudoku[i][col] == n){
            return false;
        }
    }

    for(int j=0;j<9;j++){
        if(sudoku[row][j] == n){
            return false;
        }
    }

    int r = row/3;
    int c = col/3;
    for(int i=(3*r);i<(3*(r+1));i++){
        for(int j=(3*c);j<(3*(c+1));j++){
            if(sudoku[i][j] == n){
                return false;
            }
        }
    }

    return true;
}

bool findEmptyLocation(int sudoku[9][9],int &row, int &col){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool sudokuhelper(int sudoku[9][9]){
    int row,col;
    if(!findEmptyLocation(sudoku,row,col)){
        return true;
    }
    for(int i =1;i<=9;i++){
        if(isSafe(sudoku,row,col,i)){
            sudoku[row][col] = i;
            if(sudokuhelper(sudoku)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}

int main(){

    //take input from the user
    int sudoku[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> sudoku[i][j];
        }
    }
    bool val = sudokuhelper(sudoku);
   /* for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << sudoku[i][j];
        }
        cout << endl;
    }
    */
    if(val == 1)    cout << "true";
    else    cout << "false";
    // write your code here
}