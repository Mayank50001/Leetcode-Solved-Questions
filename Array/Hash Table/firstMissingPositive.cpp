/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 
Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1

*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int firstMissingPositive(vector<int>& nums){
    int n = nums.size();
    unordered_map<int , bool> present;
    int maxi = 0;
    for(int i = 0; i < n; i++){

        //mark the current element as present only if it's greater than 0 and it's not absent in the array.
        if(nums[i] > 0 && !present[nums[i]]){
            maxi = max(maxi , nums[i]);
            present[nums[i]] = true;
        }
    }

    //If max element is negative, return 1 as default else find the first missing positive
    if(maxi > 0){
        for(int i = 1; i < maxi; i++){
            if(!present[i]){
                return i;
            }
        }
        return maxi + 1;
    }
    else {
        return 1;
    }
}

int main(){
    vector<int> arr = {-5};
    int num = firstMissingPositive(arr);
    cout << num;
}

//Approach
/*
My first thought approach to this question is pretty simple for a hard question such this.
First we track the maximum element which will use in after logic to find the first missing positive, and use an unordered map with int , bool pair to mark positive elements as present, here as values in unordered map is in boolean format, we are skipping duplicate and negative elements while traversing the array
Then we check if the max element is positive or not, if it's positive then we start from 1 and upto our tracked max element find which positive element is not present, when found return it, and if all elements are present from 1 to max element then return max + 1 as next first positive element. 

This approach is slower for the first thoughts but would improve it in future when learnt some new approach.
*/