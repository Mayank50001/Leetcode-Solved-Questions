/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Diagram :- 1 -> 1 -> 2 -> 3 -> 3
Output  :- 1 -> 2 -> 3
Input: head = [1,1,2,3,3]
Output: [1,2,3]
 
Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

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

ListNode* deleteDuplicates(ListNode* head){
    if(head -> next == nullptr) return head;

    ListNode* i = head;

    //Loop until next node is present
    while(i && i->next){

        //If value of current and next node is same, skip next node and link current node's next to 2 nodes ahead
        if(i->val == i->next->val) i->next = i->next->next;

        //Else move forward
        else i = i->next;
    }

    return head;    
}

int main(){
    ListNode* head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));

    head = deleteDuplicates(head);

    ListNode* temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
}

//Approach
/*
We just simply check if current node's and next node's value are same, if yes then next node is duplicate and question asks us to skip that node, so we just link our next pointer to next node's next node (i hope this makes sense)
*/