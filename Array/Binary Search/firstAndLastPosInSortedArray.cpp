/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
 
Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();

    //Default return answer vector
    vector<int> ans(2 , -1);
    int s = 0 , e = n - 1;
    while(s <= e){
        int mid = s + (e - s) / 2;

        if(nums[mid] == target){
            s = e = mid;

            //When Target found, traverse for the start range and end range
            while(s >= 0 && nums[s] == target){
                s--;
            }
            while(e < n && nums[e] == target){
                e++;
            }

            //Prepare the answer vector with the answer start and end indexes
            ans[0] = s + 1;
            ans[1] = e - 1;
            break;
        }
        else if(nums[mid] < target){
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    return ans;
    
}

int main(){
    vector<int> arr = {5 , 7 , 7 , 8 , 8 , 10};
    vector<int> range = searchRange(arr , 8);
    cout << "From: " << range[0] << ", To: " << range[1] << endl;
}

//Approach

/*
A simple binary search does the job, just search for the element and simple linear traverse at both ends for start and end ranges
*/