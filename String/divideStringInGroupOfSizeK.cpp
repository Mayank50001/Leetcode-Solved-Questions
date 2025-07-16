/*
A string s can be partitioned into groups of size k using the following procedure:

The first group consists of the first k characters of the string, the second group consists of the next k characters of the string, and so on. Each element can be a part of exactly one group.
For the last group, if the string does not have k characters remaining, a character fill is used to complete the group.
Note that the partition is done so that after removing the fill character from the last group (if it exists) and concatenating all the groups in order, the resultant string should be s.

Given the string s, the size of each group k and the character fill, return a string array denoting the composition of every group s has been divided into, using the above procedure.

 
Example 1:

Input: s = "abcdefghi", k = 3, fill = "x"
Output: ["abc","def","ghi"]
Explanation:
The first 3 characters "abc" form the first group.
The next 3 characters "def" form the second group.
The last 3 characters "ghi" form the third group.
Since all groups can be completely filled by characters from the string, we do not need to use fill.
Thus, the groups formed are "abc", "def", and "ghi".

Example 2:
Input: s = "abcdefghij", k = 3, fill = "x"
Output: ["abc","def","ghi","jxx"]
Explanation:
Similar to the previous example, we are forming the first three groups "abc", "def", and "ghi".
For the last group, we can only use the character 'j' from the string. To complete this group, we add 'x' twice.
Thus, the 4 groups formed are "abc", "def", "ghi", and "jxx".
 
Constraints:

1 <= s.length <= 100
s consists of lowercase English letters only.
1 <= k <= 100
fill is a lowercase English letter.

*/

#include<iostream>
#include<vector>

using namespace std;

vector<string> divideString(string s, int k, char fill) {
    vector<string> groups;

    for(int i = 0;i < s.length();i += k){

        //Have an empty group
        string group = "";

        //Loop k times to extract k characters to form a group
        for(int j = 0;j < k;j++){

            //If the current group range is out of range of string, fill the group with fill characters else append current character to group
            if(i + j < s.length()){
                group += s[i + j];
            }
            else
                group += fill;
        }

        //Push group to groups
        groups.push_back(group);
    }

    return groups;
}

int main(){
    string s = "abcdefghij";
    vector<string> ans = divideString(s , 3 , 'x');
    for(string s : ans){
        cout << s << endl;
    }
}

//Approach is quite simple
/*
We first take groups vector and traverse whole string, inside loop run another loop that runs k times to extract k characters for the group
Form groups of k characters and if the inner loop goes out of range of original string, then fill the current group with fill character and end loops.
*/