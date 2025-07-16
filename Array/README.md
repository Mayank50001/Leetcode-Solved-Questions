# 📂 Topic: Arrays

This folder contains LeetCode problems related to Arrays — including subtopics like **Binary Search**, **Prefix Sum**, and **Sorting**.

---

## ✅ Problems Solved

| Problem no. | Problem Name | File | Tag notes |
|-------------|--------------|------|-----------|
| 1 | Two Sum | `Hash Table/twoSum.cpp` | Hash Table |
| 11 | Container with most water | `Two Pointers/containerWithMostWater.cpp` | Two pointers at both end of array, greedy in the loop |
| 27 | Remove Element | `Two Pointers/removeElement.cpp` | Move non vals to front with non val pointer |
| 34 | Find First and Last Position in Sorted Array | `Binary Search/firstAndLastPosInSortedArray.cpp` | Binary Search the target, traverse for range | 
| 35 | Search Insert Position | `Binary Search/searchInsertPosition.cpp` | Binary search if element is found else index for the element |
| 41 | First Missing Positive | `Hash Table/firstMissingPositive.cpp` | hash map and max element tracked to find first missing positive |
| 46 | Permutations | `Recursion and Backtracking/permutations.cpp` | Recursion on the array while swapping elements |
| 69 | Sqrt(x) | `Binary Search/sqrtx.cpp` | Binary Search on 0 - Num search space |
| 75 | Sort Colors | `Hash Table/Sorting/SortColors.cpp` | Dutch National Flag | 
| 81 | Search in Rotated and Sorted Array II | `Binary Search/searchInRotatedAndSortedArray2.cpp` | Extra conditioned pivot finding for search |
| 88 | Merge Sorted Arrays | `Two Pointers/mergeSortedArray.cpp` | Two pointers on both array from behind |
| 121 | Best time to buy and sell stock | `Dynamic Programming/stockProblem.cpp` | Keep track of the profit of sequential minimum and maximum prices |
| 189 | Rotate Array | `Two Pointers/rotateArray.cpp` | Store and replace logic with two pointers while counting rotated elements |
| 283 | Move Zeroes | `Two Pointers/moveZeroes.cpp` | Track non zero index and swap |
| 303 | Range Sum Query - Immutable | `Prefix Sum/rangeSumQuery.cpp` | Class design, prefix sum setup and Find |
| 594 | Longest Harmonious Subsequence | `Sliding Window/longestHarmoniousSequence.cpp` | Sliding window on sorted array |
| 724 | Pivot Index | `Prefix Sum/findPivot-724.cpp` | Prefix Sum |
| 852 | Find Peak Element | `Binary Search/findPeakElement.cpp` | Binary Search |
| 1207 | Unique No. of Occurrences | `Hash Table/uniqueNoOfOccurrences.cpp` | Hash Table to track frequency of all elements | 
| 1394 | Find Largest Lucky Number | `Hash Table/luckyInteger.cpp` | Hash Table to count frequency and check frequency equality |
| 1752 | Check if array is sorted and rotated | `checksortedAndRotated.cpp` | One or zero pair check for sorted and rotated arrays |
| 2016 | Maximum difference between increasing elements | `maxDiffofIncreasingElement.cpp` | Keep track of sequential pairs of minimum and maximum elements |
| 2099 | Find Subsequence of Length K With the Largest Sum | `Sorting/subsequenceOfKWithLargestSum.cpp` | Sorting | Sorting based on value and then index of pair vector |
| 2294 | Sorting | Partition Array such that Maximum Difference is K | `Sorting/partitionArrayWithMaxDiffK.cpp` | Dynamic Difference checked subsequences formed, logic same as Q.2966 |
| 2410 | Maximum Matching of Players with Trainers | `maxMatchOfPlayersAndTrainers.cpp` | Two pointers on both players and trainers, compare and slide |
| 2966 | Divide Array into Arrays with Maximum Difference K | `Sorting/maxDifferenceArrayDivision.cpp` | Sort and form 3 sized of groups of Difference checked elements |


---

## Tips to solve problems

- Always check the input range of problem
- Many of the problem's condition checks revolve around input range of the problem
- Sorting problems have hidden need of hash table to store elements with their indexes and perform work for result based on that hash table. Keep in mind!
- If the question has 'solve in log n time' and you need something to do with searching, then it's screaming for binary search, just do it, find the search space and start solving by reducing search space to get answer. 
- If array is sorted, take binary search everytime in consideration as a possible pattern
- Some problems are solved by circular logic where we have to traverse back to first element, use % operator there
- Find count of ___ or condition based subset or subsequence types of problems are either solved by sliding window or hash table or two pointers
- For recursion problems check for the first step to be taken right now, and the base case, rest of the thing will be handled by recursion itself
- Some questions are straightforward in concept and logic as well, just because we have done so many problems of finding patterns and complex logics, doesn't mean that a questions can't have a straight forward logic.

---


