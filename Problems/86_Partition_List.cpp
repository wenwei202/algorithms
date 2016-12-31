/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* partitionNode = NULL;
        ListNode* curNode = head;
        ListNode* preNode = NULL;
        while(curNode){
            if(curNode->val < x){
                if(preNode) {
                    preNode->next = curNode->next;
                }else{
                    head = curNode->next;
                }
                
                if(partitionNode) {
                    curNode->next = partitionNode->next;
                    partitionNode->next = curNode;
                }else{
                    curNode->next = head;
                    head = curNode;
                }
                
                partitionNode = curNode;
            }
            preNode = curNode;
            curNode = curNode->next;
        }
        return head;
    }
};