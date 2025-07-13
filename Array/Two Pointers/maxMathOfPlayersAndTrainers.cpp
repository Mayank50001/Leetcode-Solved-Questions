/*
You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.
The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity. Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.
Return the maximum number of matchings between players and trainers that satisfy these conditions.

Example 1:
Input: players = [4,7,9], trainers = [8,2,5,8]
Output: 2
Explanation:
One of the ways we can form two matchings is as follows:
- players[0] can be matched with trainers[0] since 4 <= 8.
- players[1] can be matched with trainers[3] since 7 <= 8.
It can be proven that 2 is the maximum number of matchings that can be formed.

Example 2:
Input: players = [1,1,1], trainers = [10]
Output: 1
Explanation:
The trainer can be matched with any of the 3 players.
Each player can only be matched with one trainer, so the maximum answer is 1.
 
Constraints:
1 <= players.length, trainers.length <= 105
1 <= players[i], trainers[j] <= 109

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

    //Sort both arrays
    sort(players.begin() , players.end());
    sort(trainers.begin() , trainers.end());
    int p = players.size();
    int t = trainers.size();
    
    int f = 0 , s = 0;

    int m = 0;

    //Every player should have at most 1 trainer, it means a trainer or a player can be kept idle, so run until either player or trainer array get's exhausted
    while(f < p && s < t){

        //if player has less or equal training capacity of trainer, it's a match, move to next player and increment match
        if(players[f] <= trainers[s]){
            f++;
            m++;
        }

        //Move to next trainer in either case 
        s++;
    }

    return m;

}

int main(){
    vector<int> players = {4 , 7 , 9};
    vector<int> trainers = {8 , 2 , 5 , 8};
    
    int matches = matchPlayersAndTrainers(players, trainers);
    cout << matches;
}


//Approach 
/*
The two pointer approach is pretty simple, we iterate from both players and trainers array to find matches
First sort to make it easy for us to make comparison for matches, after sorting it's sensible to think that when we put two pointers one on player array and one on trainer's, if player[i] > trainer[i] , that trainer won't be able to be matched with any of other players in the player array, so move trainer pointer to next, and if player[i] <= trainer[i] , then we can match it and move both player and trainer pointer to next one as they are now matched and won't be allocated to any other players or trainers.
*/