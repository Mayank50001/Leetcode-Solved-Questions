/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.


Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

*/

#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int n = nums.size();

    //index pointer to non value index
    int nonval = 0;
    for(int i = 0; i < n; i++){

        //If current value isn't the target value, then simply place it at non value index and increment the index for next one. 
        if(nums[i] != val){
            nums[nonval++] = nums[i];
        }
    }

    //Return the non val index as our count of modified vector
    return nonval;
}

int main(){
    vector<int> nums = {0 , 1 , 2, 2 , 3 , 0 , 4 , 2};
    cout << "Length of value removed array is: " << removeElement(nums , 2);    
}

//Two pointers approach
/*
Approach includes having one pointer pointing to index where next non value integer is to be placed and one pointer will be the iterator which traverses our vector
While traversing, we check if current element is our target, if not then we place it at non val index, increment our pointer for next non val integer to be placed and move forward
We are following this approach because question says that it doesn't matter what you place after the expected elements, so we just simply put non target values as they appear during traversing to the front of the vector, neglecting the back of vector beyond expected k value.

Time taken - O(n) space - O(1)

*/