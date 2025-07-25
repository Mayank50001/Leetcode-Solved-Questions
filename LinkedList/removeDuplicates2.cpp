/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]
 

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

    //Taking dummy node before head as there's a possibility that first two nodes of list can be duplicate
    ListNode* dummy = new ListNode(0 , head);
    ListNode* prev = dummy;

    while(head){

        //If next 2 nodes are duplicate
        if(head -> next && head->val == head->next->val){
            //Move head forward until different valued node is found
            while(head -> next && head->val == head->next->val){
                head = head->next;
            }

            //Link our prev pointer to next nodes of found duplicates
            prev->next = head->next;
        }
        else{
            prev = prev->next;
        }
        head = head->next;
    }

    return dummy->next;
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

//Approach - similar to first version of duplicates problem
/*
In the first version of duplicate nodes problem, we were asked to delete only duplicate nodes exclusively, like if 1 occurs 3 times then delete it's 2 occurences leaving it 1 time and same for every duplicate

In this problem we have to delete the duplicate nodes inclusively means if 1 occurs 3 times then delete all 3 nodes
So the approach is same as first duplicate problem, the difference is as we have to delete inclusive nodes also we keep a prev pointer which points to previous single occurred node, and when duplicates are found then traverse through all duplicates and link prev->next to next node of duplicates

Means for example
List = 1 -> 2 -> 3 -> 3 -> 3 -> 4 -> 5 -> 5 -> 5-> 5 -> 6
Here prev pointer will be at 2 as both and 1 and 2 occurred single times, 3 is found to be 3 times, so prev means node 2's next will be linked to last occurred node 3, making the list as 1->2->4->5->5->5->6
Same for node valued 5, making the list as 1->2->4->6
*/