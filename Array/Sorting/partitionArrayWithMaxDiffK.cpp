/*
You are given an integer array nums and an integer k. You may partition nums into one or more subsequences such that each element in nums appears in exactly one of the subsequences.

Return the minimum number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is at most k.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.


Example 1:
Input: nums = [3,6,1,2,5], k = 2
Output: 2
Explanation:
We can partition nums into the two subsequences [3,1,2] and [6,5].
The difference between the maximum and minimum value in the first subsequence is 3 - 1 = 2.
The difference between the maximum and minimum value in the second subsequence is 6 - 5 = 1.
Since two subsequences were created, we return 2. It can be shown that 2 is the minimum number of subsequences needed.

Example 2:
Input: nums = [1,2,3], k = 1
Output: 2
Explanation:
We can partition nums into the two subsequences [1,2] and [3].
The difference between the maximum and minimum value in the first subsequence is 2 - 1 = 1.
The difference between the maximum and minimum value in the second subsequence is 3 - 3 = 0.
Since two subsequences were created, we return 2. Note that another optimal solution is to partition nums into the two subsequences [1] and [2,3].

Example 3:
Input: nums = [2,2,4,5], k = 0
Output: 3
Explanation:
We can partition nums into the three subsequences [2,2], [4], and [5].
The difference between the maximum and minimum value in the first subsequences is 2 - 2 = 0.
The difference between the maximum and minimum value in the second subsequences is 4 - 4 = 0.
The difference between the maximum and minimum value in the third subsequences is 5 - 5 = 0.
Since three subsequences were created, we return 3. It can be shown that 3 is the minimum number of subsequences needed.
 
Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
0 <= k <= 105
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;

//Simple version
int partitionArray(vector<int>& nums, int k) {
    sort(nums.begin() , nums.end());

    //Count of partitions
    int count = 1;

    //Start index of a partition, start from 0
    int start = 0;

    for(int i = 1;i < nums.size();i++){

        //If difference between current element and start of partition > k, we have to move to new partition, hence increase count and mark current index as start of new partition
        if(nums[i] - nums[start] > k){
            count++;
            start = i;
        }
    }

    return count;
}

//Fast version
int partitionArray2(vector<int>& nums, int k) {

    //Exist bitset
    bitset<100001> exists;

    //Minium value in array
    int minV = nums[0];

    //Maximum value in array
    int maxV = nums[0];

    //Traverse the array to find minimum, maximum elements and mark all elements are existing in the bitset
    for (auto v: nums) {
        minV = std::min(minV, v);
        maxV = std::max(maxV, v);
        exists[v] = true;
    }

    //Partition count
    int seq = 1;

    //Start of partition, initially at minimum value
    int start = minV;

    //Traverse from mimimum value to maximum value
    for (int v = minV; v <= maxV; ++v) {

        //Check if the value exists in our array using bitset value check
        if (exists[v]) {

            //If ecists, check if difference > k, increase partition count, and mark current element as start of new partition
            if (v - start > k) {
                start = v;
                ++seq;
            }
        }
    }

    return seq;
}

int main(){
    vector<int> nums = {3,6,1,2,5};
    cout << "Count of partitions with max difference K: " << partitionArray(nums , 2);
}

//Approach
/*
The comments in the code are self explanatory
The difference between two methods is that the first one sorts in Nlogn time hence its slower 
Second version instead marks the existent elements in a bitset, finds minimum and max element of array and traverse in the range of max and min instead of the actual array, it rather checks if the values in the range are existing in the array, if yes we go with the logic of parition difference check else move forward, with this we reduce time of sorting and work upon in just O(n) time.
*/