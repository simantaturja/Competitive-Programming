/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        int number_of_nodes = 0;
        ListNode *curr = head, *last_node = head;
        while (curr != NULL) {
            last_node = curr;
            curr = curr->next;
            ++number_of_nodes;
        }
        if (number_of_nodes <= 2) return;
        
        curr = head;
        int temp_count_nodes = 0;
        ListNode *list1 = head, *list2 = NULL;
        
        while (curr != NULL) {
            if (temp_count_nodes == number_of_nodes / 2 - 1) {
                list2 = curr->next;
                curr->next = NULL;
            }
            ++temp_count_nodes;
            curr = curr->next;
        }
        ListNode *prev = list2, *preserve_next_node = NULL;
        curr = prev->next;
        prev->next = NULL;
    
        while (curr != NULL) {
            preserve_next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = preserve_next_node;
        }
        ListNode *list1_head = head, *list2_head = last_node;
        while (list1_head != NULL) {
            ListNode *preserve_list1_next = list1_head->next;
            ListNode *preserve_list2_next = list2_head->next;
            list1_head->next = list2_head;
            list2_head->next = preserve_list1_next;
            
            list2_head = preserve_list2_next;
            if (preserve_list1_next == NULL) break;
            list1_head = preserve_list1_next;
        }
        list1_head->next->next = list2_head;
        return;
    }
};
