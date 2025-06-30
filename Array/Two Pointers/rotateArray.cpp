/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.


Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Constraints:
1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105

*/

#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<int>& nums , int k){
    int n = nums.size();
    if(n == 0 || k <= 0) return;

    
    int cnt = 0 , start = 0 , curr = 0 , numtoberotated = nums[0] , tmp = 0;
    //Iterate until all elements of vector are not rotated
    while(cnt < n){
        //Do the first rotation
        do{
            //Store current element on current index + k index
            tmp = nums[(curr+k)%n];
            nums[(curr+k)%n] = numtoberotated;
            //Update next number to be rotated,increase count and curr index
            numtoberotated = tmp;
            cnt++;
            curr = (curr+k)%n;
            
            //If vector is of even length, curr pointer will come to start pointers and perform the same cycle with same elements, so this condition is for that to stop repeated cycle with same element
        } while(curr != start);


        //Prepare for next cycle of elements
        start++;
        curr = start;
        numtoberotated = nums[curr];
    }
}

int main(){
    vector<int> nums = {1 , 2 , 3 , 4 , 5 , 6 , 7};
    cout << "Before moving: ";
    for(int i : nums){
        cout << i << " ";
    }
    rotate(nums , 3);
    cout << endl << "After moving: ";
    for(int i : nums){
        cout << i << " ";
    }    
}

/*
Approach :- Two pointers

First we take first element as our number to be rotated, we place that element after k indices and take the replaced element as number to be rotated in next cycle, after each replacement we increase our count to track how many elements got rotated and when the condition meet that every element is rotated we stop
But there's a twist, in even curr pointer will come to start index repeatedly, for example, in vector of len 4, and k = 2 , first replacement will be at index 2 and next replacement will be at index 0 again (as 2+2 = 4 %4 = 0) which would form a redundant cycle, so to avoid it we formed a condition to stop the do while loop, incremenet start so as the curr pointer and number to be rotated for the next rotation cycle.
*/