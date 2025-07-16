/*
You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.

Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:

The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

 
Example 1:
Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
Output: [[1,1,3],[3,4,5],[7,8,9]]
Explanation:
The difference between any two elements in each array is less than or equal to 2.

Example 2:
Input: nums = [2,4,2,2,5,2], k = 2
Output: []
Explanation:
Different ways to divide nums into 2 arrays of size 3 are:
[[2,2,2],[2,4,5]] (and its permutations)
[[2,2,4],[2,2,5]] (and its permutations)
Because there are four 2s there will be an array with the elements 2 and 5 no matter how we divide it. since 5 - 2 = 3 > k, the condition is not satisfied and so there is no valid division.

Example 3:
Input: nums = [4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11], k = 14
Output: [[2,2,2],[4,5,5],[5,5,7],[7,8,8],[9,9,10],[11,12,12]]
Explanation:
The difference between any two elements in each array is less than or equal to 14.


Constraints:

n == nums.length
1 <= n <= 105
n is a multiple of 3
1 <= nums[i] <= 105
1 <= k <= 105

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> divideArray(vector<int>& nums, int k) {
    int size = nums.size();
    
    sort(nums.begin(), nums.end());

    //Answer vector, having size / 3 vectors of length 3
    vector<vector<int>> result(size / 3, vector<int>(3));
    int groupIndex = 0;

    //Traverse in group of 3
    for (int i = 0; i < size; i += 3) {

        //If next 2 elements are in array range and difference of 3rd and 1st element of forming group is less than k, is's a valid group so insert it in answer and move forward;
        if (i + 2 < size && nums[i + 2] - nums[i] <= k) {
            result[groupIndex] = { nums[i], nums[i + 1], nums[i + 2] };
            groupIndex++;
        }
        else {
            return vector<vector<int>>();
        }
    }
    return result;
}

int main(){
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    vector<vector<int>> ans = divideArray(nums , 2);
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < 3;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }    
}

//Approach
/*
As we have done it in code, we sort the array first with the intuition that when the sorted array is placed in the group of 3 elemnets each, in each group if difference between 3rd and 1st element <= k, then that groups are our answer else no
So after sorting, we traverse the array in the group of 3 and check our difference condition, if valid, just add those group to answer vector, and even if single group doesn't pass our check, we return empty answer vector.
*/