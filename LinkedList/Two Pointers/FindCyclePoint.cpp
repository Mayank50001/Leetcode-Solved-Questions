/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 
Example 1:
Diagram : 3 -> 2 -> 0 -> -4 ->
               ^             |
               |             |
               _______________

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
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

ListNode* detectCycle(ListNode* head){
    if(head->next == nullptr){
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast -> next){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            slow = head;
            while(slow == head){
                fast = fast->next;
                slow = slow->next;
                return slow;
            }
        }
    }

    return nullptr;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    for(int i = 2;i <= 4;i++){
        ListNode* newNode = new ListNode(i);
        temp->next = newNode;
        temp = newNode;
    }
    
    temp->next = head->next;
    ListNode* ans = detectCycle(head);

    if(ans){
        ans->next = nullptr;
        cout << ans->val;
    }
    else{
        cout << "No cycle";
    }

    return 0;
}

//Floyd's cycle point finding algorithm
/*
We know how to find if cycle is present
But there's another proven theory where after detecting cycle, we point slow pointer to head and move both pointers on step at a time instead fast moving by 2. When both pointers again meet at a node, that node is considered to be the node where the last supposed node of the list is pointing to

For example
Input ;- 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> To node3
Iteration1 :- fast = 1, slow = 1
Iteration2 :- fast = 3, slow = 2
Iteration3 :- fast = 5, slow = 3
Iteration4 :- fast = 7, slow = 4
Iteration5 :- fast = 4 (7 points back to 3), slow = 5
Iteration6 :- fast = 6, slow = 6
At this point fast and slow pointer meet hence cycle is present, now move slow back to 1
So list pointers will be slow = 1, fast = 6
Move pointers = slow = 2, fast = 7 
Move pointers = slow = 3, fast = 3 (7 points back to 3)

At 2nd iteration both pointers again meet which tells us that this theory works, just try with more examples yourself.

*/