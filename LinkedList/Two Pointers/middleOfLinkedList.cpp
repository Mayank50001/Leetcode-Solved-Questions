/*
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 
Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100

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

ListNode* middleNode(ListNode* head) {
    if(head -> next == nullptr){
        return head;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

int main(){
    ListNode* head = new ListNode();
    ListNode* temp = head;
    for(int i = 1; i <= 6; i++){
        ListNode* newNode = new ListNode(i);
        temp -> next = newNode;
        temp = newNode;
    }

    head = head -> next;
    ListNode* result = middleNode(head);
    temp = result;
    while(temp){
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl << endl;
}

//Approach
/*
Approach is simple, we have used fast and slow pointer , where fast pointer moves by 2 pointers, and slow moves just 1 pointer ahead.
But when fast pointer reaches the end of the list, it is sensible to think that if fast pointer has reached the end with 2x speed than slow pointer, then slow pointer would be at half distance of the list. 
So just return slow pointer. 
*/