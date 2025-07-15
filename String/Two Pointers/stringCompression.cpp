/*
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.

The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

Example 1:
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

Example 2:
Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.

Example 3:
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
 
Constraints:
1 <= chars.length <= 2000
chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.

*/

#include<iostream>
#include<vector>

using namespace std;

int compress(vector<char> s){

    int n = s.size();

    char prev = s[0];
    int len = 1;
    string result = "";
    for(int i = 1;i < n;i++){

        //If current char = our prev char, increase the length
        if(s[i] == prev)
            len++;
        
        //When not, it means we have found a different character
        else{
            //So if length of our last series of same chars is 1, just push the character to result
            if(len == 1)
                result.push_back(prev);

            //Else first push character and append the length's string format to the result
            else{
                result.push_back(prev);
                string num = to_string(len);
                result.append(num);
            }

            //Set prev to current char as now start a new series of characters, len to 1 
            prev = s[i];
            len = 1;
        }
    }

    //After complete loop, the last character will be left, push it 
    result.push_back(prev);
    result.append(to_string(len));

    return result.length();
}

int main(){
    vector<char> s = {'a' , 'a' , 'a' , 'a' , 'b' , 'c' , 'c' , 'd' , 'd' , 'd'};

    int count = compress(s);
    cout << count;
}

//Approach
/*
We keep track of a prev character and length.
During traversal when same characters are found as prev character, just increase our length, when different are found, then we find if our last length is 1, if yes, push only the character (according the requirements of our question) else also append the string format of our length value, at the end return our result string's length
*/