#include<iostream>
#include<string.h>
#include<stdlib.h>
#define N 9
using namespace std;
bool works(int grid[N][N], int row, int col){
  for (int num = 0; num < N; num++){
      for (int num2 = 0; num2 < N; num2++){
        if ((grid[num][col] != 0 && grid[num][col] == grid[num2][col] && num !=num2)){
          return false;
      }
      if ((num !=num2 && grid[row][num] == grid[row][num2] && grid[row][num] != 0)){
        return false;
      }
    }

  }
  return true;

}
void print(int grid[N][N]){
  for (int x=0; x<N;x++){
    for (int y=0; y<N;y++){
      cout << grid[x][y];
    }
    cout << "\n";
  }
}
bool solve(int grid[N][N], int row, int col){
    if ((col == N)&&(row == N-1)){
      return true;
    }

    if (col == N){
      col = 0;
      row = row + 1;

    }
    if (grid[row][col] != 0){
      col = col + 1;
      return solve(grid, row, col);
    }
    for (int num = 1; num < N+1; num++){
      grid[row][col] = num;
      if (works(grid, row, col)){
        if (solve(grid, row, col+1)){
          return true;
        }


      }else{
      }
    }
    grid[row][col] = 0;
    return false;

}
int main(){

  int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };



  solve(grid, 0, 0);
  print(grid);





}
