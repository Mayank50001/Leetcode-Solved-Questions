/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.
The most significant bit is at the head of the linked list.

Example 1:
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

Example 2:
Input: head = [0]
Output: 0

Constraints:
The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.

*/

#include<iostream>
#include<math.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0) , next(nullptr) {}
	ListNode(int x) : val(x) , next(nullptr) {}
	ListNode(int x , ListNode* next) : val(x) , next(next) {}
};

int getDecimalValue(ListNode* head) {
        int len = 1;
        ListNode* temp = head;

	//For finding length of the linked list
        while(temp->next){
            temp = temp -> next;
            len++;
        }

        temp = head;
        int ans = 0 , i = len - 1;
        while(temp){
	    //Keep adding the binary base index value to decimal as per the formula
            ans += (pow(2 , i) * temp -> val);
            temp = temp -> next;
            i--;
        }

        return ans;
    }

int main() {
	ListNode* n3 = new ListNode(1);
	ListNode* n2 = new ListNode(0,n3);
	ListNode* n1 = new ListNode(1,n2);

	int decimal = getDecimalValue(n1);
	cout << "Decimal for the corresponding list is: " << decimal << endl;
}

//Approach is simple to understand
/*
First we find out the length of our linked list, as this is not a doubly linked list we have to traverse from the start for binary to integer conversion
Once we find length, we can then calculate binary to integer based on the 2^i where i starts from len - 1 all the way to 0 which correctly find s the integer equivalent.
*/
