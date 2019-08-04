/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
  bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    TreeNode* x_node = root;
    int before_num = 0;
    if (x != 1) {
      x_node = countBeforeParent(root, x, before_num);
    }

    int left_num = 0, right_num = 0;
    if (x_node->left) {
      left_num = countTree(x_node->left);
    }
    if (x_node->right) {
      right_num = countTree(x_node->right);
    }

    vector<int> nums = {before_num, left_num, right_num};
    std::sort(nums.begin(), nums.end());
    return (nums[2] > (nums[0] + nums[1] + 1));
  }

  TreeNode* countBeforeParent(TreeNode* root, int x, int& count) {
    // preorder tranversal
    stack<TreeNode*> pre_stack;
    pre_stack.push(root);
    count = 0;
    TreeNode* x_node = NULL;
    while (!pre_stack.empty()) {
      TreeNode* cur_node = pre_stack.top();
      pre_stack.pop();
      if (cur_node->val == x) {
        x_node = cur_node;
      } else {
        count ++;
        if (cur_node->left) {
          pre_stack.push(cur_node->left);
        }
        if (cur_node->right) {
          pre_stack.push(cur_node->right);
        }
      }
    }

    return x_node;
  }

  int countTree(TreeNode* root) {
    stack<TreeNode*> pre_stack;
    pre_stack.push(root);
    int count = 0;
    while (!pre_stack.empty()) {
      TreeNode* cur_node = pre_stack.top();
      pre_stack.pop();
      count++;
      if (cur_node->left) {
        pre_stack.push(cur_node->left);
      }
      if (cur_node->right) {
        pre_stack.push(cur_node->right);
      }
    }

    return count;
  }

};
