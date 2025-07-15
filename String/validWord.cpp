/*
A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.
Notes:
'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.
 
Example 1:
Input: word = "234Adas"
Output: true
Explanation:
This word satisfies the conditions.

Example 2:
Input: word = "b3"
Output: false
Explanation:
The length of this word is fewer than 3, and does not have a vowel.

Example 3:
Input: word = "a3$e"
Output: false
Explanation:
This word contains a '$' character and does not have a consonant.

Constraints:
1 <= word.length <= 20
word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.

*/

#include<iostream>

using namespace std;

bool isValid(string word) {
    int n = word.length();

    //First rule, if word has less than 3 characters, it's not valid
    if (n < 3) return false;

    string vowels = "aeiouAEIOU";
    int vowel = 0 , cons = 0;
    for(char s : word){
        //If character is an alphabet
        if(isalpha(s)){
            //Check if it's a vowel
            if(vowels.find(s) != string::npos)
                //Increment count of vowel
                vowel++;

            //Else it's a consonant
            else 
                cons++;
        }

        //Else check if it's a digit, if not it's other than alphanumeric range and hence not valid.
        else if(!isdigit(s))
            return false;
    }

    //Return true if count of there at least one vowel and a consonant
    return vowel >= 1 && cons >= 1;
}

int main(){
    string word = "234Adas";
    cout << isValid(word);
}

//Approach
/*
Self explanatory with the comments of the code itself.
We first check our length rule, then define string of vowels (both lowercase and uppercase)
Then traverse our string and check if character is alphabet or digit, if alphabet it can either be a vowel or a consonant, so increment their values likewise.
If not alphabet, its digit, and if it's not a digit, then there's a symbol and that's invalid so return false
Finally return true if there's at least one vowel and one consonant
*/