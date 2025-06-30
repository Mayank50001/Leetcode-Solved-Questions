/*
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation:
The longest harmonious subsequence is [3,2,2,2,3].

Example 2:
Input: nums = [1,2,3,4]
Output: 2
Explanation:
The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.

Example 3:
Input: nums = [1,1,1,1]
Output: 0
Explanation:

No harmonic subsequence exists.


Constraints:

1 <= nums.length <= 2 * 104
-109 <= nums[i] <= 109

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findLHS(vector<int>& nums) {
    //Sort the vector
    sort(nums.begin() , nums.end());
    int maxLength = 0;
    //J is for start of window
    int j = 0;
    for(int i = 0;i < nums.size();i++){
        //Move start of window forward, until element at end and start of window have a difference less than 2
        while(nums[i] - nums[j] > 1)
            j++;

        //Update max length whenever end of window and start of window make up a difference of 1
        if(nums[i] - nums[j] == 1)
            maxLength = max(maxLength , (i - j) + 1);
    }

    return maxLength;
}

int main(){
    vector<int> nums = {3 , 2 , 4 , 3 , 2 , 6 , 5 , 8 , 1 , 1};
    cout << findLHS(nums);
}


//Approach :- sliding window
/*
We first need to sort the vector so that sliding the window would be possible
after sorting elements, we can easily iterate over the vector and check for some conditions
Put start of window to first element check in every iteration if end of window and start of window has difference of 1, then update the maxLength , and if the difference is greater than 1 then slide the start of window upto the point where difference remains 1.
Rest is cleared by code itself,it's straightforward.
*/