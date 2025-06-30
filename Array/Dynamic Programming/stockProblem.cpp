/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 
Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices){
    //Current buy set to first day
    int buy = prices[0];
    int profit = 0;
    for(int i = 0;i < prices.size();i++){
        //Current buy is <= previous buy
        if(prices[i] <= buy)
            buy = prices[i];
        else
            //update max profit based on previous track of our profit and current profit we are gaining
            profit = max(profit , (prices[i] - buy));
    }

    return profit;
}

int main(){
    vector<int> prices = {7 , 1 , 5 , 3 , 6 , 4};
    cout << "Maximum profit is: " << maxProfit(prices);    
}

//Approach :- raw thinking
/*
The array is given with random values, a beginner may think to sort the price array and return the difference between max and minimum price but here it's not applicable as in original array minimum element could be the last element which would make our result opposite of what we got with sorting

So while iterating our array in 0(N) time we keep track of small element, and update profit if higher price occurs while iterations 

There may be a condition where we get even smaller price than our current buy, in that case we have a chance that we can get more profit after that price day, so we store our current profit and continue finding profit based on our max profit function
*/