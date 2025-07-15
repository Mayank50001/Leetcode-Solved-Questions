/*
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

Example 1:
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Example 2:
Input: s = "azxxzy"
Output: "ay"
 
Constraints:
1 <= s.length <= 105
s consists of lowercase English letters.

*/

#include<iostream>

using namespace std;

string removeDuplicates(string s){
    string result = ""; //This works like a stack

    for(char c:s){

        //Check if stack is not empty and top of stack has same character as current character
        if(!result.empty() && result.back() == c){

            //Then pop it out
            result.pop_back();
        }

        //Else push it on the stack
        else{
            result.push_back(c);
        }
    }

    return result;
}

int main(){
    string s = "abbaca";
    string result = removeDuplicates(s);
    cout << result;
}

//Approach
/*
The stack approach of removing duplicates, the classic one!
We setup a stack as our result
We iterate over string and check each character, if it is already at the top of stack, that means it's adjacently duplicate and we need to remove them, so just pop it from the result string (stack) and move to next characters, no overhead of deleting it from the original string, and if both characters are different then just push it.
At the end of string iteration, return the result string (stack) 

This method is O(n) in time and O(n) in space but it doesn't matter right?
*/