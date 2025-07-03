/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head){
    //Start from the head
    ListNode* temp = head;

    //Another linked list which to be returned reversed
    ListNode* reversed_head = nullptr;
    while(temp!=nullptr){
        int value = temp->val;
        //Create new node with value of temp , and next pointer to reversed head
        ListNode* node = new ListNode(value, reversed_head);

        //Move reversed head back to the node which lead to insertion at head
        reversed_head = node;
        temp = temp->next;
    }

    return reversed_head;
}

int main()
{
    ListNode* head = new ListNode();
    ListNode* temp = head;
    for(int i = 1;i <= 5;i++){
        ListNode* newNode = new ListNode(i);
        temp->next = newNode;
        temp = newNode;
    }

    temp = head;
    head = head->next;

    ListNode* reversed = reverseList(head);

    temp = reversed;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
}

//Approach
//We just have to traverse the linked list and create a new node with value of our given list's node, and every time just insert that node at head which forms a reversed linked list due to insertion at head everytime
//Everytime we are moving forward, we are inserting new node to our reversed list at head instead of at end which makes our list reversed.