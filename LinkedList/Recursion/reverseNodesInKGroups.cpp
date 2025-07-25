/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Diagram :- 
Input           1 -> 2 -> 3 -> 4 -> 5 
Output          2 -> 1 -> 4 -> 3 -> 5   (List reversed in k = 2 nodes)
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 
Follow-up: Can you solve the problem in O(1) extra memory space?

*/

#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0) , next(nullptr) {}
	ListNode(int x) : val(x) , next(nullptr) {}
	ListNode(int x , ListNode* next) : val(x) , next(next) {}
};

ListNode* reverseK(ListNode*& head, int k){
    ListNode* prev = nullptr;
    ListNode* curr = head;

    //Tail pointer that will point to the tail of the currently reversed k node list's last node.
    ListNode* tail = curr;
    ListNode* next = nullptr;

    int cnt = 0;

    //Checking if k nodes are present in the list, else we don't have to reverse if insufficient nodes are there.
    ListNode* check = curr;
    for(int i = 0;i < k;i++){
        if(!check) return curr;
        check = check->next;
    }

    //Reverse k nodes
    while(cnt < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    //Point the reversed returned linked list after recursion to the tail of the currently reversed list.
    tail->next = reverseK(curr,k);
    return prev;

}

int main(){
    ListNode* head = new ListNode();
    ListNode* temp = head;
    for(int i = 1;i <= 5;i++){
        ListNode* newNode = new ListNode(i);
        temp->next = newNode;
        temp = newNode;
    }

    temp = head;
    head = head->next;

    ListNode* reversed = reverseK(head, 2);

    temp = reversed;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
}

