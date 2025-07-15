/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
head        1 -> 2 -> 3 -> 4 -> 5
rotate 1 =  5 -> 1 -> 2 -> 3 -> 4
rotate 2 =  4 -> 5 -> 1 -> 2 -> 3

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

*/

#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0) , next(nullptr) {}
    ListNode(int x) : val(x) , next(nullptr) {}
    ListNode(int x , ListNode* next) : val(x) , next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(!head) return head;
    
    int len=1; // number of nodes
    ListNode *newH, *tail;
    newH=tail=head;
    
    while(tail->next)  // get the number of nodes in the list
    {
        tail = tail->next;
        len++;
    }
    tail->next = head; // circle the link

    //If k is perfectly divided by length, that means list doesn't need to be rotated or after rotating, it will be of same form as original
    if(k %= len) 
    {
        for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
    }
    newH = tail->next; 
    tail->next = NULL;
    return newH;
}

int main(){
    ListNode* head = new ListNode();
    ListNode* temp = head;
    for(int i = 1; i <= 5; i++){
        ListNode* newNode = new ListNode(i);
        temp -> next = newNode;
        temp = newNode;
    }

    head = head -> next;
    ListNode* result = rotateRight(head , 2);
    temp = result;
    while(temp){
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl << endl;
}

//Approach
/*
When we are said to rotate the list, a beginner (like me ofcourse ;) ) would think to change the nodes of all the list by rotating them whole, but the this question is too easy for two pointers approach
First we link the tail of the list to head to make it circular because we know that after rotating, the list will be in form where head of the original list would be next to tail in the new list
Then we just need to find the (len-k)-th node from the end of the list which will be our head node of the rotated list, and after moving upto that node, make it new head and cutoff it's last node's next pointer to make it back to singly, and return our new list.
*/