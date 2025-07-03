/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
 
Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?
*/

#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Two pass
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* temp = head;

    //Count variable to count nodes
    int count = 0;
    while(temp!=nullptr){

        //Count nodes
        count++;
        temp = temp->next;
    }
    ListNode* prev = nullptr;
    temp = head;

    //If first element is to be deleted
    if(n == count){
        head = head->next;
        return head;
    }
    else{
        //Move pointer to the point where temp pointer is pointing to node to be deleted
        for(int i = 1;i < (count - n + 1);i++){
            prev = temp;
            temp = temp->next;
        }
        //Erasing the node
        prev->next = temp->next;
        temp->next = nullptr;
        delete temp;
    }

    return head;
}

ListNode* removeNthFromEnd2(ListNode* head , int n){
    ListNode* dummy = new ListNode(0 , head);
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    //Move fast pointer upto n + 1 nodes
    for(int i = 0;i <= n;i++){
        fast = fast->next;
    }

    //Keep moving the fast pointer ahead so that when it's null, slow pointer's next will be pointing to the node to be deleted
    while(fast){
        fast = fast->next;
        slow = slow->next;
    }

    //Erase the node
    ListNode* delnode = slow->next;
    slow->next = slow->next->next;
    delnode->next = nullptr;
    delete delnode;

    return dummy->next;
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

    ListNode* result = removeNthFromEnd2(head , 2);

    temp = result;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
}

//Approach 
/*
1. Plain method:-
Traverse the list to the end and store the count of nodes
Traverse the list again from start upto n - k + 1 nodes, then delete the node the temp is pointing to and manage the addresses to return result list
*/

/*
2. Two Pointers
Initialize two pointers, slow and fast, both pointing to the head of the list
Then move the fast pointer by n+1 nodes, when that happens move both fast pointer and slow pointer which was at head forward until fast pointer becomes nullptr
When that happens, now we are in a situation where our slow pointer's next is pointing the node to be deleted from the list
JUST DELETE THAT NODE!!!!!!
Return
*/