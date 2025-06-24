/*
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.

 

Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1

Example 3:
Input: arr = [0,10,5,2]
Output: 1

Constraints:
3 <= arr.length <= 105
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.
*/

//Approach:-
/*
    Array with a peak element is like a binary tree with 2 flanks where left flank have elements less than peak in increasing order from index 1 and right flank has elements in decreasing order
    We know that peak left side and right side of a peak element is always smaller than it
    Therefore condition 1 = if arr[mid] < arr[mid + 1] , we are on the left flank hence s = mid+1
    else we are on the right flank and maybe on the peak element so e = mid and not mid-1
    
    at last return s
*/

#include<iostream>
#include<vector>
using namespace std;

int peakIndexInMountainArray(vector<int> arr){
    //Start basic prequesites of binary search
    int s = 0 , e = arr.size() - 1;
    while(s < e){
        int mid = s + (e - s)/2;

        //if our current mid element is small than next element then it's clearly stating that we are on left flank and peak is far more ahead, so place start next to mid and continue searching
        if(arr[mid] < arr[mid + 1]){
            s = mid + 1;
        }

        //Else either we are on right flank or on the peak element but not sure as there may be a more greater element than mid on left side so place end at mid and continue searching
        else{
            e = mid;
        }
    }

    return s;
}

int main(){
    vector<int> arr = {1 , 3 , 7 , 9 , 4 , 2};
    cout << "Index of peak array is: " << peakIndexInMountainArray(arr);
}