/*
Given the head of a linked list head, in which each node contains an integer value.
Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.
Return the linked list after insertion.
The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

Example 1:
original    18    ->   6    ->   10    ->   3
inserted    18 -> 6 -> 6 -> 2 -> 10 -> 1 -> 3

Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
There are no more adjacent nodes, so we return the linked list.

Example 2:
Input: head = [7]
Output: [7]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes.
There are no pairs of adjacent nodes, so we return the initial linked list.
 
Constraints:
The number of nodes in the list is in the range [1, 5000].
1 <= Node.val <= 1000*/

#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0) , next(nullptr) {}
    ListNode(int x) : val(x) , next(nullptr) {}
    ListNode(int x , ListNode* next) : val(x) , next(next) {}
};

int calculateGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ListNode* insertGreatestCommonDivisors(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* node1 = head;
    ListNode* node2 = head->next;

    while (node2 != nullptr) {
        int gcdValue = calculateGCD(node1->val, node2->val);
        ListNode* gcdNode = new ListNode(gcdValue);

        // Insert gcdNode between node1 and node2
        node1->next = gcdNode;
        gcdNode->next = node2;

        // Move to the next pair of nodes
        node1 = node2;
        node2 = node2->next;
    }

    return head;
}

int main(){
    ListNode* node4 = new ListNode(18);
    ListNode* node3 = new ListNode(6 , node4);
    ListNode* node2 = new ListNode(10, node3);
    ListNode* node1 = new ListNode(3, node2);

    ListNode* head = insertGreatestCommonDivisors(node1);
    while(head){
        cout << head -> val << " ";
        head = head -> next;
    }
}

//Approach
/*
It should be in two pointers section but thik he chalta he itna, it has major work of math theory
First we take two pointers as we have to find gcd of two node's values and insert it as a node between then,
so from head and it's next node, start traversing the list, and in each iteration, find gcd of those two node's values using our euclid's gcd theorem and insert the resultant value's node in between node1 and node2 then move to next pair of nodes while checking the loop condition.
*/