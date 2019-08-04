/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

  struct NodeWrap {
    NodeWrap(TreeNode* node) : node_(node) {
      left_proced = right_proced = false;
    }
    TreeNode* node_;
    bool left_proced;
    bool right_proced;
  };

public:
  int longestUnivaluePath(TreeNode* root) {
    int max_length = 0;
    if (root) {
      processTree(root, max_length);
      return max_length - 1;
    }
    return 0;
  }

  void processTree(TreeNode* root, int& max_length) {
    int max_left = 0,  max_right = 0;
    if (root->left) {
      processTree(root->left, max_left);
    }
    if (root->right) {
      processTree(root->right, max_right);
    }

    if (root->left && root->left->val == root->val ||
        root->right && root->right->val == root->val) {
      int root_max_len = searchMaxRootPath(root);
      max_length = std::max(root_max_len, std::max(max_left, max_right));
      return;
    }

    max_length = std::max(1, std::max(max_left, max_right));
    return;
  }

  int searchMaxRootPath(TreeNode* root) {
    const int val = root->val;
    int max_length = 1;
    if (root->left && root->left->val == val) {
      max_length += searchMaxSubTree(root->left, val);
    }
    if (root->right && root->right->val == val) {
      max_length += searchMaxSubTree(root->right, val);
    }

    return max_length;
  }

  int searchMaxSubTree(TreeNode* sub_root, int val) {
    int max_length = 1;
    stack<NodeWrap> search_stack;
    search_stack.push(NodeWrap(sub_root));
    while (!search_stack.empty()) {
      NodeWrap& cur_wrap = search_stack.top();
      TreeNode* cur_node = cur_wrap.node_;
      if (cur_node->left && !cur_wrap.left_proced && cur_node->left->val == val) {
        search_stack.push(NodeWrap(cur_node->left));
        cur_wrap.left_proced = true;
      } else if (cur_node->right && !cur_wrap.right_proced && cur_node->right->val == val) {
        search_stack.push(NodeWrap(cur_node->right));
        cur_wrap.right_proced = true;
      } else {
        search_stack.pop();
      }
      if (max_length < search_stack.size()) {
        max_length = search_stack.size();
      }
    }
    return max_length;
  }

};

int main() {
  TreeNode* tree = new TreeNode(5);
  TreeNode *l1_1 = new TreeNode(4), *l1_2 = new TreeNode(5), *l2_1 = new TreeNode(1);
  TreeNode *l2_2 = new TreeNode(1), *l2_3 = new TreeNode(5);
  tree->left = l1_1; tree->right = l1_2;
  l1_1->left = l2_1; l1_1->right = l2_2; l1_2->right = l2_3;
  Solution sln = Solution();
  int res = sln.longestUnivaluePath(tree);

  std::cout << "res: " << res << std::endl;

  return 0;
}
