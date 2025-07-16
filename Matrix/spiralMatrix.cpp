/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
   ->
  1 -> 2 -> 3 |
| 4 -> 5    6 |
| 7 <- 8 <- 9 |

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int count = 0;
    int total = rows * cols;
    int startingRow = 0;
    int endingRow = rows - 1;
    int startingCol = 0;
    int endingCol = cols - 1;

    while(count < total){

        for(int i = startingCol;count < total && i <= endingCol;i++){
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;

        for(int i = startingRow;count < total && i <= endingRow;i++){
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        for(int i = endingCol;count < total && i >= startingCol;i--){
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        for(int i = endingRow;count < total && i >= startingRow;i--){
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }

    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3} ,{4,5,6} ,{7,8,9}};
    vector<int> ans = spiralOrder(matrix);
    for(int i = 0;i < ans.size();i++){
        cout << ans[i] << " ";
    }
}