/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* head = new ListNode(-1);
    vector<ListNode*> node_ptrs(lists.size());

    // initialize all ptr
    for (size_t i = 0; i < lists.size(); i++) {
      node_ptrs[i] = lists[i];
    }

    ListNode* cur_ptr = head;
    while (!allEnd(node_ptrs)) {
      ListNode* min = NULL;
      int idx = -1;
      for (size_t i = 0; i < node_ptrs.size(); i++) {
        if (node_ptrs[i]) {
          if (!min) {
            min = node_ptrs[i];
            idx = i;
          } else if (node_ptrs[i]->val < min->val) {
            min = node_ptrs[i];
            idx = i;
          }
        }
      }
      ListNode* new_node = new ListNode(min->val);
      node_ptrs[idx] = node_ptrs[idx]->next;
      cur_ptr->next = new_node;
      cur_ptr = new_node;
    }

    cur_ptr = head->next;
    delete head;

    return cur_ptr;
  }

  bool allEnd(vector<ListNode*>& node_ptrs) {
    for (size_t i = 0; i < node_ptrs.size(); i++) {
      if (node_ptrs[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {

}
