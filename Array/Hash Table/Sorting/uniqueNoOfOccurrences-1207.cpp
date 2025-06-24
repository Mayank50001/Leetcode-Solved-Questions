//Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

/*
Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/

//Approach we are going to use
//Hash table :- We will count and store each digit's freq in hash table, then create a set and insert each element from freq hash table , which would naturally remove duplicate elements as it's a set , then check if size of both freq table and set is equal, if yes then array elements have unique number of occurences so return true else return false


#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

bool uniqueOccurrences(vector<int> nums){
    unordered_map<int , int> freq;

    //Count and store frequency of each element in hash table
    for(auto x : nums){
        freq[x]++;
    }

    //Create a set to store frequencies as unique ones
    unordered_set<int> s;
    for(auto x:freq){
        s.insert(x.second);
    }

    //Return true if sizes are equal which means set still have unique freqs as in hash table else false
    if(s.size() == freq.size()) return true;
    else return false;


}

int main(){
    vector<int> nums = {1 , 1 , 2 , 2 , 3 , 3 , 1};
    cout << uniqueOccurrences(nums) << endl;
}