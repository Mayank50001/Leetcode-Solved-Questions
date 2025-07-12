/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
 
Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

*/

#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0) , next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x , ListNode *next) : val(x) , next(next) {}
};

ListNode* mergeSortedList(ListNode* list1 , ListNode* list2){

    //Base case
    if(!list1) return list2;
    if(!list2) return list1;

    //RR 1
    if(list1 -> val < list2 -> val){
        // Perform current operation and let recursion do the rest
        list1 -> next = mergeSortedList(list1 -> next , list2);
        return list1;
    }
    //RR 2
    else {
        // Perform current operation and let recursion do the rest
        list2 -> next = mergeSortedList(list1 , list2 -> next);
        return list2;
    }
}

int main(){
    ListNode* node3 = new ListNode(7);
    ListNode* node2 = new ListNode(4, node3);
    ListNode* node1 = new ListNode(1, node2);

    ListNode* node6 = new ListNode(3);
    ListNode* node5 = new ListNode(2 , node6);
    ListNode* node4 = new ListNode(1 , node5);

    ListNode* head = mergeSortedList(node1 , node4);
    while(head){
        cout << head -> val << " ";
        head = head -> next;
    }
}

//Approach
/*
The recursive relation is actually easy to think for most practitioners. Our bigger problem is to merge those lists, but our smaller solution to it is that, put smallest -> biggest node order in answer list
So we check the value and according to the comparison, We recursive find the small nodes and keep connecting them while backtracking in the recursion tree
A dry run would better visualize this
list1 = 1 -> 2 -> 4 and 
list2 = 1 -> 3 -> 4
return answer is at top of call stack
call stack                                                  returned list2 
-----------------------------------------------------------------------------------------------
mergeSortedList((1 , 2 , 4) , (1 , 3 , 4)) = 1 == 1 , so    list2 = 1 -> 1 -> 2 -> 3 -> 4 -> 4
mergeSortedList((1 , 2 , 4) , (3 , 4)) = 1 < 3, so          list1 = 1 -> 2 -> 3 -> 4 -> 4
mergeSortedList((2 , 4) , (3 , 4)) = 2 < 3, so              list1 = 2 -> 3 -> 4 -> 4
mergeSortedList((4) , (3 , 4)) = 4 < 3, so                  list2 = 3 -> 4 -> 4
mergeSortedList((4) , (4)) = 4 == 4, so                     list2 = 4 -> 4
mergeSortedList((4) , (nullptr)) return list1
-----------------------------------------------------------------------------------------------
*/