/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 
Constraints:
1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/

#include<iostream>
#include<unordered_map>

using namespace std;

//My first thought approach
int romanToInt(string s){
    unordered_map<char , int> romanToInt = {
        {'I' , 1},
        {'V' , 5},
        {'X' , 10},
        {'L' , 50},
        {'C' , 100},
        {'D' , 500},
        {'M' , 1000}
    };

    int n = s.length();
    int num = 0;
    for(int i = 0;i < n;i++){

        //Check every possible smaller succeeded by larger roman pair, perform operations according to that
        if(s[i] == 'I' && s[i + 1] == 'V'){
            num += romanToInt['V'] - 1;
            i++;
            continue;
        }
        if(s[i] == 'I' && s[i + 1] == 'X'){
            num += romanToInt['X'] - 1;
            i++;
            continue;
        }
        if(s[i] == 'X' && s[i + 1] == 'L'){
            num += romanToInt['L'] - 10;
            i++;
            continue;
        }
        if(s[i] == 'X' && s[i + 1] == 'C'){
            num += romanToInt['C'] - 10;
            i++;
            continue;
        }
        if(s[i] == 'C' && s[i + 1] == 'D'){
            num += romanToInt['D'] - 100;
            i++;
            continue;
        }
        if(s[i] == 'C' && s[i + 1] == 'M'){
            num += romanToInt['M'] - 100;
            i++;
            continue;
        }

    //Simply add that roman to integer mapping to our answer if no such pair found
        num += romanToInt[s[i]];
    }

    return num;
}

//Standard approach
int romanToInt2(string s){
    unordered_map<char , int> map = {
        {'I' , 1},
        {'V' , 5},
        {'X' , 10},
        {'L' , 50},
        {'C' , 100},
        {'D' , 500},
        {'M' , 1000}
    };

    int num = 0;

    for(int i = 0;i < s.length();i++){

        //If we get a pair where next roman is larger than our current roman, then subtract equivalent larger roman number from smaller one and add that to answer, also increment i + 2 so that the next roman we just calculated would be skipped and won't be added again
        if(map[s[i]] < map[s[i+1]]){
            num += (map[s[i + 1]] - map[s[i]]);
            i++;
        }
        else{
            num += map[s[i]];
        }
    }
    return num;
}

int main(){
    string roman = "MCDL";
    cout << romanToInt2(roman);
}

//Approach
/*
First thoughts are brute force, to check every possibility where smaller roman comes before larger, For example "IV" or "IX" here X has 10 value but as I comes before it, it becomes 9 which is X - I, but that would be an inefficient code with way too much condition branchings than needed

Standard thought process should be that we know that upon the condition we discussed before, we have to add the larger - smaller roman equivalent integer into the answer, so just form the condition and increment counter by 2 to skip the next larger roman we just calculated.
*/