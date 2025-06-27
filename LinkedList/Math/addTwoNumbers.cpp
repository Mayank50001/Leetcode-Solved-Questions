/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.


Illustration :- 
first list =  2 -> 4 -> 3
second list = 5 -> 6 -> 4
--------------------------
answer list = 7 -> 0 -> 8


Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list node.
 */
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * Helper function to insert a node at the tail of a linked list. No need for faster approach.
 */
void insertNode(ListNode* &head, ListNode* &tail, int data) {
    ListNode* newNode = new ListNode(data);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

/**
 * Solution class containing the logic for adding two numbers
 * represented as linked lists.
 */
class Solution {
public:
    //Naive approach for a beginner, runtime 3ms for all test cases
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val1 = 0 , val2 = 0 , carry = 0;
        ListNode* fn = l1;
        ListNode* sn = l2;
        ListNode* ln = NULL;
        ListNode* head = NULL;
        //Run until Both pointers are a node
        while(fn != NULL && sn != NULL){
            val1 = fn->val;
            val2 = sn->val;
            //Calculate the 2-digit sum first
            int sum = (val1 + val2) + carry;
            //Calculate the carry
            carry = sum / 10;
            //Create node with the value of sum with carry removed
            insertNode(head , ln , (sum%10));
            //Move both nodes forward and continue traversing
            fn = fn->next;
            sn = sn->next;
        }
        //When either of the list's node becomes empty, check which list is still remaining to be traversed
        while(fn != NULL){
            val1 = fn->val;
            int sum = val1 + carry;
            carry = sum / 10;
            insertNode(head , ln , (sum%10));
            fn = fn->next;
        }
        while(sn != NULL){
            val2 = sn->val;
            int sum = val2 + carry;
            carry = sum / 10;
            insertNode(head , ln , (sum%10));
            sn = sn->next;
        }

        //After both lists are traversed, it is possible that carry is of last node, so if it is, create another node to our answer with carry value for correct answer
        if(carry != 0){
            insertNode(head , ln , carry);
        }

        return head;
    }

    //More consice approach
    ListNode* addTwoNumbers2(ListNode* l1 , ListNode* l2){
        //Take a dummy node
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        int carry = 0;
        while(l1!=nullptr || l2!=nullptr || carry != 0){
            //this satisfies both conditions without having to write two different while loops for either of two remaining lists
            int d1 = (l1!=nullptr) ? l1->val : 0;
            int d2 = (l2!=nullptr) ? l2->val : 0;

            int data = d1 + d2 + carry;
            carry = data / 10;
            ListNode* newNode = new ListNode((data%10));
            tail->next = newNode;
            tail = newNode;

            l1 = (l1!=nullptr) ? l1->next : nullptr;
            l2 = (l2!=nullptr) ? l2->next : nullptr;
        }

        //As head is declared at dummy, return next nodes of head as the main answer
        return head->next;

        //OR
        //ListNode* result = head->next;
        //delete head;
        //return result;
    }
};

/**
 * Utility function to print a linked list.
 */
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/**
 * Sample main function to test the solution.
 */
int main() {
    // Creating first number: 5 -> 6
    ListNode* l1 = new ListNode(5);
    l1->next = new ListNode(6);

    // Creating second number: 5 -> 4 -> 9
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(9);

    Solution sol;
    ListNode* result = sol.addTwoNumbers2(l1, l2);

    cout << "Sum: ";
    printList(result);  // Expected: 0 -> 1 -> 0 -> 1

    return 0;
}
