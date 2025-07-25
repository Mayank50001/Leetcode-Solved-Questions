/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Diagram :- 
Input :-  1 -> 2 -> 3 -> 4 -> 5
Output :- 1 -> 4 -> 3 -> 2 -> 5

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]
 
Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?
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

ListNode* reverseBetween(ListNode* head , int left ,int right){
    if(head->next == nullptr){
        return head;
    }

    //If left and right are same then there is only one node and it makes sense that we don't need to reverse the list
    if (left==right) return head;

    ListNode *dummy = new ListNode(0 , head);

    //Dummy prev node in the case if left is the first node, then we will have to modify the head pointer as well in which case, dummy helps easily, rp stands for right pointer which points the right node of the range
    ListNode *prev =dummy , *curr=head , *rp = nullptr , *next = nullptr;

    int lc = 1 , rc = 1 , len = (right - left) + 1;

    //Traverse upto the left node of the range, where the prev becomes the node before it, and curr the left node
    while(lc < left){
        prev = curr;
        curr = curr->next;
        lc++;
    }

    rp = curr;
    //Now bring the right pointer to the right node of the range
    while(rc < len){
        rp = rp->next;
        rc++;
    }

    //Make links
    prev->next = rp;
    prev = curr;
    curr = curr->next;
    prev->next = rp->next;

    //Reverse the range
    while(prev != rp){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return dummy->next;
}

int main(){
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    head = reverseBetween(head , 2 , 4);
    ListNode* temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

//Approach
/*
Here we track or i would say find and store the leftmost and rightmost node of the given left and right range in curr and rp pointers respectively, as the question says 
for example for 1 -> 2 -> 3 -> 4 -> 5   curr = 2, rp = 4
Output is       1 -> 4 -> 3 -> 2 -> 5

As we can see that the curr->next pointer after reversing would be pointing to rp->next node and the prev->next node would be pointing to the rp node.

So after finding those nodes we modified the links based on this logic and after that reversed the range of list independently, it was easy I swear.


*/