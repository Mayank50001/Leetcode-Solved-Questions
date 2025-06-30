/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].

Example 2:
Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

Example 3:
Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

#include<iostream>
#include<vector>

using namespace std;

bool check(vector<int>& nums){
    int count = 0 ,n = nums.size();
    for(int i = 0;i < n;i++){
        //Count how many pairs are there where next element is smaller than first element
        if(nums[(n + i)%n] > nums[(n + i + 1)%n])
            count++;
    }

    return count <= 1;
}

int main(){
    vector<int> nums = {3 , 4 , 5 , 1 , 2};
    cout << check(nums);    
}

/*
Approach
We have a common intuition, there are 3 conditions

1st :- Array is sorted 
    For example nums = [1 , 2, 3 , 4 , 5 , 6] This is sorted array and there is only one pair of elements where next element is smaller than first element which is 6 and 1

2nd :- Array is rotated and sorted
    For example nums = [3 , 4 , 5 , 6 , 1 , 2] This is sorted and rotated array and there is only one pair of elements where next element is smalle than first element which 6 and 1, again here is also only 1 pair

3rd condition :- Array is not sorted (and not rotated if not sorted)
    for example nums = [3 , 4 , 1 , 5 , 7 , 2 , 6] This array is not sorted so not rotated as well, here are more than 1 pair where next element is smaller than first

So we can say that if such pairs are strictly 0 or 1, array is rotated, else its not sorted and rotated and that's what count does in the program
*/