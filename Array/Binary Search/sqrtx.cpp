/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 
Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 
Constraints:
0 <= x <= 231 - 1

*/

#include<iostream>

using namespace std;

int sqrt(int num){
    int s = 0 , e = num;
    int ans;
    while(s <= e){
        long long mid = s + (e - s)/2;
        long long square = (mid * mid);
        if(square == num)
            return mid;
        else if(square > num)
            e = mid - 1;
        else{
            ans = mid;
            s = mid + 1;
        }
    }

    return ans;
}

int main(){
    int num = 8;
    int root = sqrt(num);
    cout << root;
}

//Basic approach and thinking
/*
While finding the root of a number, we know it lies between 0 to the number, using loop we have implemented logic many times but what if number is big say 10^6, then loop method takes O(N) time and operations could make it even worse
So because the search space that is 0 - N is in sorted order we can find sqrt using binary search using O(log n) time
Just start with s = 0 , e = mid and continue binary search logic where if mid * mid == num then num is our answer, if mid * mid > num , then all numbers after mid aren't sqrt so reduce search space to mid - 1 and if mid * mid < num, then if is a possible answer but their could be more answers if we search up ahead, so store it in ans for now and continue searching, at last return the stored answer if perfect answer is not achieved
*/