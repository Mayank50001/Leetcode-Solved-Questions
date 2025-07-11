/*
Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.


Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Example 2:
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

Example 3:
Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
 
Constraints:
1 <= nums.length <= 104
-1000 <= nums[i] <= 1000
*/

//Approach is to start from 0th index and left sum = 0 and right sum as the whole sum of array
//Keep subtracting ith index from right sum and compare left sum with it, it matched return index
//Else add ith index element to left sum and keep iterating 
//If end of array is reached and still left sum != right sum then return -1;

#include<vector>
#include<iostream>
#include<numeric>

using namespace std;

int pivotIndex(vector<int>& nums) {
    // Initialize rightSum to store the sum of all the numbers strictly to the index's right...
    int rightSum = accumulate(nums.begin(), nums.end(), 0);
    // Initialize leftSum to store the sum of all the numbers strictly to the index's left...
    int leftSum = 0;
    // Traverse all elements through the loop...
    for (int idx = 0; idx < nums.size(); idx++) {
        // subtract current elements with from rightSum...
        rightSum -= nums[idx];
        // If the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right...
        if (leftSum == rightSum)
            return idx;     // Return the pivot index...
        // add current elements with leftSum...
        leftSum += nums[idx];
    }
    return -1; // If there is no index that satisfies the conditions in the problem statement...
}

int main(){
    vector<int> arr = {1,7,3,6,5,6};
    cout << pivotIndex(arr);
}