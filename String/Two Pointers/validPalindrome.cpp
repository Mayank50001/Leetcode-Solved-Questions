/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 
Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

#include<iostream>

using namespace std;

char toLowerCase(char ch){
    //Lowercase the character
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return ch;
    
    return (ch - 'A' + 'a');

}
bool valid(char ch){
    //Checks if character is in the range of a-z, A-Z or 0-9 , if yes,true else false
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z')){
        return true;
    }
    else{
        return false;
    }
}

bool isPalindrome(string s) {
    int st = 0 , e = s.length() - 1;
    
    while(st < e){
        //move start until valid character is not found
        if(!valid(s[st])){
            st++;
            continue;
        }
        //move end until valid character is not found
        if(!valid(s[e])){
            e--;
            continue;
        }
        
        //If start and end are not same characters, string can't be palindrome, return false
        if(toLowerCase(s[st]) != toLowerCase(s[e])){
            return false;
        }

        //Move both pointers
        st++;
        e--;
    }
    
    //If control comes up here, return true, string is palindrome
    return true;
    
}

int main(){
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s);
}

//Approach :- simple two pointers is used, one at begin, one at end, we check everytime for a valid character and then when both pointers are at valid character we check if they are same,if yes move to next iteration, else return false immediately, upon completion of loop, return true as their is not point found where those two pointers have different element.