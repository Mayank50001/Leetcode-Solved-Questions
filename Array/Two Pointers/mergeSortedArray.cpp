/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 
Constraints:
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?

*/

#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums1 ,int m , vector<int>& nums2 , int n){
    //Take 3 pointers, i for first vector, j for second vector, and k for placing correct element back to first vector
    int i = m - 1 , j = n - 1 , k = m + n - 1;
    while(i >= 0 && j >= 0){
        //Compare and place correct element from either vectors back to first vector to form answer
        (nums1[i] > nums2[j]) ? nums1[k--] = nums1[i--] : nums1[k--] = nums2[j--];
    }

    //These two while loops just in case one vector is traversed completely and one vector is left with some elements, so store the remaining elements into answer 
    while(i >= 0)
        nums1[k--] = nums1[i--];

    while(j >= 0)
        nums1[k--] = nums2[j--];
}

int main(){
    vector<int> nums1 = {1 , 2 , 3 , 0 , 0  , 0};
    vector<int> nums2 = {2 , 5 , 6};
    merge(nums1 , 3 , nums2 , 3);
    for(int i : nums1){
        cout << i << " ";
    }
}

/*
Approach is simple, as first vector is with the capacity of both vector combined we can compare every element and place them on k index, But why we are traversing elements from both vectors from the back and storing biggest elements first instead of starting from first index and place smallest elements in answer.
Answer is simple, We have to use nums1 array as our merged sorted answer vector, what happens if while storing answer, all second vectors values are smaller hence they form the first indexes of our answer vector, but the values which were there first will be overwritten and there won't be a chance to get them and store them after the elements we just stored. The main problem is overwriting of data that's all, we are merging arrays that's why this caution is taken.
*/