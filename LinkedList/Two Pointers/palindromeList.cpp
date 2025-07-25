/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false


Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9


Follow up: Could you do it in O(n) time and O(1) space?
*/

#include <iostream>
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

// Approach 1 : T.C :- O(N), S.C :- O(N)
bool isPalindrome(ListNode *head)
{
    if (head == nullptr)
        return false;
    if (head->next == nullptr)
        return true;

    ListNode *s = nullptr;
    ListNode *temp = head;

    //Make a seperate list which reversed of original linked list
    while (temp)
    {
        ListNode *node = new ListNode(temp->val, s);
        s = node;
        temp = temp->next;
    }

    while (s)
    {
        //Check equality of both nodes from original and reversed list, if it is palindrome, it should be equal for every node, else return false at exact moment where different node values are found
        if (head->val != s->val)
            return false;
        s = s->next;
        head = head->next;
    }

    return true;
}

//Approach 2 : T.C & S.C same as Approach 1
bool isPalindrome2(ListNode* head){
    vector<int> list;
    ListNode* temp = head;

    //Make a vector out of the list
    while(temp){
        list.push_back(temp->val);
        temp = temp->next;
    }

    int i = 0, j = list.size() - 1;
    //Check palindrome using classic two pointer on vector
    while(i < j){
        if(list[i] != list[j]) return false;
        i++;
        j--;
    }

    return true;
}

//Approach 3
bool isPalindrome3(ListNode* head){
    if(head->next == nullptr){
        return true;
    }

    ListNode* fast = head;
    ListNode* slow = fast;

    //Find middle of the list
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode* prev = slow;
    ListNode* curr = prev->next;
    prev->next = nullptr;
    ListNode* next = nullptr;

    //Reverse the list from the middle node to the end which will let us traverse backward
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    //Put our two pointers at both ends
    curr = prev;
    fast = head;
    while(curr){
        if(fast->val!=curr->val) return false;
        curr = curr->next;
        fast = fast->next;
    }

    return true;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));

    (isPalindrome3(head)) ? cout << "List is palindrome" : cout << "Not palindrome";
}

//Approach 1
/*
It is quite simple, we just created another list but reversed and compare them node by node, if difference is found, list is not palindrome
*/

//Approach 2
/*
We created a vector out of the list and using 2 pointers at both ends in vector, we check if it is palindrome.
*/

//Approach 3 - Now this needs explanation
/*
As list is singly, we have a problem that if we have to check both ends for palindrome, we can't traverse the list backward, so we just changed the list in the form that we first find the middle node of the list, and after that middle node to last node of the list, we reverse it
For example for list 1 -> 2 -> 2 -> 1
Half reversed list = 1 -> 2 -> 2 <- 1
Where First end up to middle is = 1 -> 2 -> 2 -> null   as per we have written the code
Second end from the last node to the middle node = 1 -> 2 -> null

So after reversing the half list, we traverse from both ends and check for equality.
*/