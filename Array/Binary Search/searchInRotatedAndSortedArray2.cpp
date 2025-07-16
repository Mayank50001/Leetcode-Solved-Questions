/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
 

Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?
*/

#include<iostream>
#include<vector>

using namespace std;

int getPivot(vector<int>& nums, int size) {
    int s = 0, e = size - 1;

    //Standard pivot finding method
    while (s < e){
        //THe only change is, as there are duplicate elements, it's possible that array can be rotated resulting both start and end having same element...See example in below explanation
        while(s < e && nums[s] == nums[e]){
            s++;
        }
        int mid = s + (e - s) / 2;

        if (nums[mid] > nums[e]) {
            s = mid + 1;
        } else {
            e = mid;
        }
    }
    return s;
}

//Standard binary search
bool binarySearch(vector<int>& nums , int start , int end , int key){
    int s = start , e = end;
    while(s <= e){
        int mid = s + (e - s)/2;
        if(nums[mid] == key){
            return true;
        }
        else if(nums[mid] > key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return false;
}

bool search(vector<int>& nums, int target) {

    //FInd pivot index
    int pivot = getPivot(nums , nums.size());

    //If pivot element is smaller than target, then our target should be at right part of rotated array, else it should be at left part......FIND IT!!!!
    if(nums[pivot] <= target && target <= nums[nums.size() - 1])
    
        return binarySearch(nums , pivot , nums.size() - 1 , target);
    else
        return binarySearch(nums , 0 , (pivot - 1) , target);
}

int main(){
    vector<int> nums = {2,5,6,0,0,1,2};
    cout << "0 is present in array: " << (search(nums , 0)) ? "Yes" : "No";
}

//Modified approach
/*
The comments are self explanatory in the code, just for the pivot method, by same start and end i mean would be cleared in below example

for example arr = [1,2,3,4,5,6]; rotate on 3rd index would result in arr = [4,5,6,1,2,3]
Now we know that to find pivot we know that rotated array's front element is always bigger than end element and on that basis we form 3 conditions and move ahead

But say arr = [1,2,3,3,4,5,6] and after rotating on 3rd index it becomes arr = [3,4,5,6,1,2,3]
Now our base condition fails as both ends have same elements, so we just shrink our search space by moving start forward and end backward if both ends have same elements, that way we will have our pointers pointing to right rule wise rotated array with arr[0] > arr[n - 1] and we can find pivot.
Rest procedure is same
*/