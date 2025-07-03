/*
You are given the head of a linked list, and an integer k.
Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Example 2:
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 
Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
*/

#include<iostream>
#include<vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Time :- O(n + n) Space :- 0(n)
ListNode* swapNodes(ListNode* head, int k) {
    ListNode* temp = head;
    vector<int> vals;

    //Traverse list and push each value of each node to a vector
    while(temp!=nullptr){
        vals.push_back(temp->val);
        temp = temp->next;
    }

    //swap indexes (k - 1) because arrays are 0 indexed
    swap(vals[k - 1] , vals[(vals.size() - k)]);
    temp = head;

    //Store values back to the original linked list after swapping
    for(int val: vals){
        temp->val = val;
        temp = temp->next;
    }

    return head;
}

//Time :- O(n+n) Space :- O(1) Still two pass
ListNode* swapNodes(ListNode* head, int k) {
    int n=0;
    ListNode* dummy=head;
    while(dummy!=NULL){
        n++;
        dummy=dummy->next;
    }
    ListNode* l1=head;
    ListNode* l2=head;
    int a=0,b=0;
    dummy=head;
    while(dummy!=NULL){
        a++;
        b++;
        if(a==k){
            l1=dummy;
        }
        if(b==n-k+1){
            l2=dummy;
        }
        dummy=dummy->next;
    }
    
    swap(l1->val,l2->val);
    return head;
}

//Time :- O(n) Space :- O(1) //One pass algorithm
ListNode* swapNodes(ListNode* head , int k){
    ListNode* end = nullptr;
    ListNode* first = nullptr;
    for(ListNode* p = head;p!=nullptr;p = p->next){
        end = (end == nullptr) ? nullptr : end->next;
        if(--k == 0){
            first = p;
            end = head;
        }
    }

    swap(first->val , end->val);
    return head;
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

    ListNode* result = swapNodes(head , 2);

    temp = result;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
}

//Approach
/*
1. Store all values of nodes in a vector, swap specified indexes in the vector and store all vector values in all nodes.
This approach uses extra space and hence it is not optimal


2. Count and iterate :- First count all nodes, then initlialize two pointers , traverse the linked list again, when k iterations are done, store the iterator node pointer in first pointer, and when n-k+1 iterations are done, store the iterate node pointer in second pointer. So we have got our two pointers for swapping, now swap both and return.
This approach doesn't demand any extra space but is a 2 pass approach

3. Same as second one, here instead of performing one extra iteration for counting, we implicitly check our count in the same list. We traverse list to the end, and inside when and only when we have iterated k times, we store that current node in first pointer and start second pointer from head, so that when we have completed traversing our list, the second pointer will be pointing to the n-k+1st node, so swap and return.
This is a one pass approach
*/