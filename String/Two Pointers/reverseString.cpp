/*
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 
Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
*/


#include<iostream>

using namespace std;

void reverseString(string& s){
    int n = s.length();
    if(n == 0 || n == 1){
        return;
    }

    int i =0 , j = n - 1;
    while(i < j){
        swap(s[i++] , s[j--]);
    }
}

int main(){
    string s = "hello";
    reverseString(s);
    cout << s;
}

//Approach:- Nothing just two pointers, swapping first and last elements with those two pointers;