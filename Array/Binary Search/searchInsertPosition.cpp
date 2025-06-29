/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
 
Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104

*/

#include<iostream>
#include<vector>

using namespace std;

int searchInsert(vector<int>& nums , int target){
    int s = 0 , e = nums.size() - 1;

    //Assume that possible answer is at the end of the vector
    int possibleAns = nums.size();

    while(s <= e){
        int mid = s + (e - s) / 2;
        if(nums[mid] == target){
            return mid;
        }

        //If target is to the left , then current index can be a possible index to return if element is not found
        else if(nums[mid] > target){
            possibleAns = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    return possibleAns;
}

int main(){
    vector<int> nums = {1 , 3 , 5 , 7};
    int index = searchInsert(nums , 4);
    cout << index;
}

//Approach
/*
The array is sorted and question says to solve in O(log n) so it is clearly a binary search problem
Twist is that if element is not present then return possible index to return so we have kept possibleAns to track a possible index
In the binary search logic whenever mid element is larger than target then it is possible that if element is not found on the left side , then the mid we worked on could be the answer
For ex take arr = [1 , 3 , 5] target = 2
mid is 3 here, but 3(mid) > 2(target) , so take index of 3 which is 1 as possible ans (which is actually correct) but as algo is not a human, move forward with the logic, now mid is 1, but 1(mid) < 2(target), so move start to mid + 1, but now start > end, so we end the logic and the possible ans we have is index 1 which is correct

even if target was 4, then in first iteration start would be at index 2 element 5, and 5 > 4, so possible answer would be index 2 after which end would be mid - 1, start > end and return 2 as final answer

That's how this algo works
*/