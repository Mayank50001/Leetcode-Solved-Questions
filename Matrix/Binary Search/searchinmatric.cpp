/*
You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.


Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

*/

#include<iostream>
#include<vector>

using namespace std;

//Utility search function
bool search(vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size() - 1;
    
    while(s <= e){
        int mid = s + (e - s)/2;
        if(nums[mid] == target){
            return true;
        }
        else if(nums[mid] > target){
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>> matrix , int target){
    //Iterate over every row
    for(int i = 0;i < matrix.size();i++){
        //If target is larger than last element of current row, move to next row 
        if(target > matrix[i][matrix[i].size() - 1])
            continue;

        //If target is less than first element of current row, bad luck break
        if(target < matrix[i][0])
            break;

        //If code reaches here, it means target can be in the current row, search it using binary search
        if(search(matrix[i] , target))
            return true;
    }

    //Return false at last
    return false;
}

int main(){
    vector<vector<int>> matrix = {{1 , 3 , 5 , 7} , {10 , 11 , 16 , 20} , {23 , 30 , 34 , 60}};
    cout << searchMatrix(matrix , 16);
}

//Intuition and approach
/*
question says to write an algorithm in O(log(m*n)) time so binary search is a must
We could have used binary search over the whole matrix by having start at 0 and end at last element of matrix
But we have a fast solution :- Search only on the row which is eligible to have the element
To find the eligible row, match target with first and last element of the current row.
If element is larger than last element of current row, move to next row and if element is smaller than first element of the row we moved to, then return false as there is nothing to be talked about, the element doesn't exist
If target is both smaller than last element and larger than first element of current row, use binary search over that row and return answer
*/