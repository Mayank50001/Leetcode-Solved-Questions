/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 
Constraints:
1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.

*/

#include<iostream>
#include<vector>

using namespace std;

bool checkInclusion(string s1 , string s2){
    if (s1.length() > s2.length()) return false;

    vector<int> freq_window(26 , 0);
    vector<int> freq_permn(26 , 0);

    //Prepare the window 
    for(char c : s1){
        freq_window[c - 'a']++;
    }

    int windowSize = s1.length();
    //Set the window on the rails of s2
    for(int i = 0;i < windowSize;i++)
        freq_permn[s2[i] - 'a']++;

    //Check permutation after window setup
    if (freq_window == freq_permn) return true;

    //Slide the window on the rails
    for(int i = windowSize;i < s2.length();i++){
        //include new character into the window;
        freq_window[s2[i] - 'a']++;

        //Remove old character
        freq_window[s2[i - windowSize] - 'a']--;

        if (freq_window == freq_permn) return true;
    }

    return false;
}

int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << checkInclusion(s1 , s2);
}

//Approach
/*
The standard sliding window approach
Permutation has a meaning that combinations after scrambling the characters of a string, but indirect meaning of that is that however or whatever number of combinations we find, the frequency of each character in all permutations is going to be same
We are using that principle, first we prepare our window by counting char frequencies of our s1
then we set our window on s2 and count frequency of same no of characters in s2 as s1, and check if both frequencies match, then it's permutation, else slide the window by adding next character of s2 and removing first element of our window and rematch them, return based on these conditions.
*/