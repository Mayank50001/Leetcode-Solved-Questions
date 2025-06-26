/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//Brute force method
//Time complexity : O(n^2)
//Space complexity : O(1)
vector<int> bruteforcetwosum(vector<int>& nums , int target){
    vector<int> ans;
    //Find all pairs of elements that sum up to target
    for(int i = 0;i < nums.size() - 1;i++){
        for(int j = i + 1;j < nums.size();j++){
            if (nums[i] + nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }
    return ans;
}

//Hash table
//TIme complexity :- O(n)
//Space complexity :- O(n)
vector<int> optimizedtwosum(vector<int>& nums , int target){
    unordered_map<int , int> maps;
    vector<int> ans;

    //Iterate over every element
    for(int i = 0;i < nums.size();i++){
        //Find the second element required based on first element
        int y = target - nums[i];
        //If the required element is available, then that's the answer, return both indexes
        if(maps.count(y) && maps[y] != i){
            return {i , maps[y]};
        }
        //If not found store the current element in hash table and move forward
        else{
            maps[nums[i]] = i;
        }
    }
    
    return {};
}

int main(){
    vector<int> nums = {2 , 7 , 11 , 15};
    vector<int> pair;
    pair = bruteforcetwosum(nums , 9);
    cout << pair[0] << pair[1];

    pair = optimizedtwosum(nums , 9);
    cout << pair[0] << pair[1];
}

/*
First train of thought always goes towards bruteforcing , finding all pairs 
Second thought arises that if while bruteforcing ,if our element of inner loop becomes greater than target then next elements can't be answers so break the inner loop and continue next iteration of outer loop
For more optimal approach we find a way, that we iterate over the array and subtract every ith element from target 
if the result element exists in array then we have found our answer or continue and iterating and follow the process
Using hash table allows for faster lookup of elements which makes the program superfast than bruteforce
*/