/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.


Example 1:
Diagram : 1 -> 2 -> 3 -> 4 ->
               ^            |
               |            |
               ______________

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?

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

bool hasCycle(ListNode* head){
    if(head->next == nullptr){
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast -> next){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            return true;
        }
    }

    return false;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    for(int i = 2;i <= 4;i++){
        ListNode* newNode = new ListNode(i);
        temp->next = newNode;
        temp = newNode;
    }

    
    (hasCycle(head)) ? cout << "Cycle detected" : cout << "Cycle not found";

    return 0;
}

//Floydd's cycle detection algorithm
/*
This algorithm works with fast and slow pointer theory
There's a theory and practically proven practical implementation of 2 pointers to detect cycle in a linkedlist

We start both pointers from head, move fast pointer 2 nodes at a time while also checking for if current or next node fast is pointing to is valid or not, if it's nullptr then it's not a circular linked list and we will return false as a cycle having list would not have any node pointing to nullptr

While traversing the list (if cycle is present) fast moving 2 steps and slow only 1 time, there will be a time when both pointers would be pointing to the same node, at that time we will return true

Example 
Input ;- 1 -> 2 -> 3 -> 4 -> back to head
Iteration1 :- fast = 1 , slow = 1
Iteration2 :- fast = 3, slow = 2
Iteration3 :- fast = 2(4 points back to 2), slow = 3
Iteration4 :- fast = 4, slow = 4


So on iteration4 both pointers meet and here we can return true, if there was no cycle, then after iteration 2 fast would been pointing to a nullptr after node 4 and there loop would have terminated and we would have returned true, that is another case, this is another case.
*/