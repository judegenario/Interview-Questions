
/*Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    
    struct ListNode* newNode = NULL;
    
    while (head) {
        struct ListNode* aux = head->next;
        
        head->next = newNode;
        newNode = head;
        head = aux;
    }
    return newNode;
}

