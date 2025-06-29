/*

Given a string s, find the length of the longest substring without duplicate characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


//Time complexity O(n^2) at worst due to nested find and substr functions - reason for 15ms runtime
int lengthOfLongestSubstring(string s) {
    //Edge case for the length of string as 0 or 1
    if(s.length() == 0) return 0;
    if(s.length() == 1) return 1;

    //Initialize starting length as 1 and starting window with first character of string
    int len = 1;
    string window;
    window.push_back(s[0]);
    int original = s.length();

    //Iterate over the string
    for(int i = 1;i < original;i++){
        //Find the ith char of original string in our window
        size_t found = window.find(s[i]);

        //If found
        if(found != string::npos){
            //assign the window's length if it's larger than current length
            len = (len < window.length()) ? window.length() : len;    
            //Reduce our window upto the repeating character, preserving string after repeating character 
            window = window.substr(found + 1);
        }
        //Add current character in our window
        window.push_back(s[i]);
    }

    //Final check of length
    len = (len < window.length()) ? window.length() : len;  

    return len;
}

//Optimized version of sliding window
int lengthOfLongestSubstring2(string s){
    if(s.length() == 0) return 0;
    if(s.length() == 1) return 1;

    //Hash map for tracking all characters
    unordered_map<char , int> lastSeen;
    int maxLen = 0;

    //Start of window
    int start = 0;

    //Iterate over string
    for(int i = 0;i < s.length();i++){
        //If current char is in hashmap and it's in our window
        if(lastSeen.find(s[i]) != lastSeen.end() && lastSeen[s[i]] >= start){
            //Update our start of window +1 after start of last window
            start = lastSeen[s[i]] + 1;
        }

        //Update current char's last seen track in hashmap
        lastSeen[s[i]] = i;
        maxLen = max(maxLen , i - start + 1);
    }
    return maxLen;   
}

int main(){
    string s = "abcabcbb";
    int substring = lengthOfLongestSubstring(s);
    cout << substring << endl;

    s = "ahendileoscldelastedlseffsse";
    substring = lengthOfLongestSubstring2(s);
    cout << substring << endl;

}

/*
Approach :-
First anyone would think about solving this question in two pointers just like the first version i wrote above which became sliding window without my realization
We just simply traverse the original string and search for the current char in our window using string functions such as find, if current char is available in window, we use substr method to reduce our window to the next index of repeating character and update current length also. At last return the length
But this method uses 2 string functions , find() and substr() which are O(n) and are used nested too in which in worst case our algo's complexity becomes O(n^2) and a 15ms runtime on leetcode

Optimized approach is to use hash table, and start variable
while iterating over string, start will be the start of window , and i will be the end of window
Keep updating current character in hashmap and check if that char is in our window , if yes, then move and reduce our window to the next point of repeating character and update hashmap with latest results, at last return length
This approach uses hash map which makes it a O(n) to the whole.

*/