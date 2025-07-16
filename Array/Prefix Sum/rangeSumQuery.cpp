/*
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

Example 1:

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]
Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
0 <= left <= right < nums.length
At most 104 calls will be made to sumRange.

*/

#include<iostream>
#include<vector>

using namespace std;

class NumArray{
    public:
        vector<int> nums;
        vector<int> psum;
        NumArray(vector<int>& nums){
            this -> nums = nums;
            prefixSum(nums);
        }

        void prefixSum(vector<int>& nums){
            psum.resize(nums.size());
            int sum = 0;
            for(int i = 0; i < nums.size(); i++){
                psum[i] = (sum += nums[i]);
            }
        }

        int sumRange(int left, int right) {
            if (left == 0)
                return psum[right];

            return psum[right] - psum[left - 1];
        }
};

int main(){
    vector<int> nums = {-2,0,3,-5,2,-1};
    NumArray* np = new NumArray(nums);
    cout << np->sumRange(2 , 5);
}

/*
This problem is pretty easy but it adds up some twist with the class design concept
We are asked to return sum of elements between a range of index. For designing a class, we first instantiate the nums array for our class by constructor, and initialize our prefix sum array psum in the same constructor. We know how to do prefix sum, right?

Now for the sumRange method, we use our prepared psum array to find the sum in range by standard formula of psum[endRange] - psum[startRange - 1], This finds the sum in a range. This is a standard formula
*/