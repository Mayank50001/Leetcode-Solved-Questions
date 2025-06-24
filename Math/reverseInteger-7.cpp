/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 
*/

#include<iostream>
#include<climits>
using namespace std;

int reverse(int num){
    int rev = 0 , rem;
    while(num){
        int rem = num % 10;
        if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && rem > 7))
            return 0;
        else if(rev < INT_MIN /10 || (rev == INT_MIN / 10 && rem < -8))
            return 0;

        rev = rev * 10 + rem;
        num /= 10;
    }

    return rev;
}

int main(){
    cout << reverse(123) << endl;
    cout << reverse(-123) << endl;
    cout << reverse(120) << endl;
    cout << reverse(3124309270) << endl;
}