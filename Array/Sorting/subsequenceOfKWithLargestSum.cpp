/*
You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.
Return any such subsequence as an integer array of length k.
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.

Example 2:
Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.

Example 3:
Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].

Constraints:
1 <= nums.length <= 1000
-105 <= nums[i] <= 105
1 <= k <= nums.length
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> valIndex;

        // Step 1: Store value and original index
        for (int i = 0; i < n; ++i) {
            valIndex.push_back({nums[i], i});
        }

        // Step 2: Sort by value in descending order
        sort(valIndex.begin(), valIndex.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        // Step 3: Take top k elements (value, index)
        vector<pair<int, int>> topK(valIndex.begin(), valIndex.begin() + k);

        // Step 4: Sort top k elements by original index
        sort(topK.begin(), topK.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        // Step 5: Build the result from sorted indices
        vector<int> result;
        for (auto &p : topK) {
            result.push_back(p.first);
        }

        return result;
    }

int main(){
    vector<int>  nums = {2 , 1 , 3 , 3};
    vector<int> subsequence = maxSubsequence(nums , 3);
    for(int i = 0;i < subsequence.size();i++){
        cout << subsequence[i] << " ";
    }
}

//Approach intuition
//At first look this problem looks easy(it actually is) , then we think we could just sort the array in descending order and pick first k elements as answer but it's not straightforward
//Question says to return the subsequence in order they appear in original order, meaning we have to return our largest k elements we found after sorting in the order they appear in the orginal order they appear before sorting
//Solution to this is to preserve the index of the elements, here i have used pair to store values and indexes
//Sort the pair vector, pick first k elements from the pair vector which would be in our answer and for returning them in order , just sort the answer pair vector according to index, it will sort based on index and we can send that pair vector as answer