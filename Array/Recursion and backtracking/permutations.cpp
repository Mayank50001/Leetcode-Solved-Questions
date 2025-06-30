/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/

#include<iostream>
#include<vector>

using namespace std;

void backtrack(vector<int>& nums , int idx , vector<vector<int>>& ans){
    //Base case
    if(idx <= 0){
        ans.push_back(nums);
        return;
    }

    for(int i = idx;i < nums.size();i++){

        //Swap idx with current element to get a different set of permutations of the part of array
        swap(nums[i] , nums[idx]);

        //Recurse to find more sets of permutations
        backtrack(nums , idx + 1 , ans);

        //Backtrack to have the array intact for next element chain
        swap(nums[i] , nums[idx]);
    }
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    if(nums.size() == 1){
        ans.push_back(nums);
        return ans;
    }

    backtrack(nums , 0 , ans);
    return ans;
}

int main(){
    vector<int> nums = {1 , 2 , 3};
    vector<vector<int>> ans = permute(nums);
    
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[0].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

//Approach :- Backtracking