/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]

Constraints:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?
*/

#include<iostream>
#include<vector>

using namespace std;

void moveZeroes(vector<int>& nums){
    //Start non zero index with 0
    int nonZero = 0;
    for(int i = 0;i < nums.size();i++){
        //For every non zero element , move it non zero index increment non zero index for next non zero element
        if(nums[i] != 0){
            nums[nonZero++] = nums[i];
        }
    }

    //After all non zero elements are moved, start from non zero index and start placing 0s till the end of vector
    for(int i = nonZero;i < nums.size();i++)
        nums[i] = 0;
}

int main(){
    vector<int> nums = {0 , 1 , 0 , 3 , 12};
    cout << "Before moving: ";
    for(int i : nums){
        cout << i << " ";
    }
    moveZeroes(nums);
    cout << endl << "After moving: ";
    for(int i : nums){
        cout << i << " ";
    }
}

//Approach :- Two pointers
/*
This question is little bit confusing for beginners. It says to move zeroes without changing the relative order of other elements, many of us(including me) think to use 2 pointers, one for zero and one for non zero element
Whenever a non zero element occurs and first pointer is at zero just swap them, it's possible to do like that but it's becomes complicated with more nested condition checks and all.
So instead of tracking zero and non zero elements, we take the question as to move non zeros to front.We initialize non zero pointer to first index, and iterate the vector, upon finding any non zero , we just place it in place the non zero 
pointer, when we have done iterating, we start from non zero index again and till the end place zero which would make array as we have moved all zeroes to the end, but what we have actually done logically is moving non zero elements to front which was easy to implement
*/