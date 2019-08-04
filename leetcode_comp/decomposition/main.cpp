#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
  int longestDecomposition(string text) {
    const char* str_ptr = text.c_str();
    const char *left_p = str_ptr, *right_p = str_ptr + text.length() - 1;

    int sub_str = 0;
    vector<char> left_cache, right_cache;
    bool success_sub_str = true;
    while (left_p < right_p) {
      success_sub_str = false;
      left_cache.push_back(*left_p);
      right_cache.push_back(*right_p);
      if (compareLeftRightSubstr(left_cache, right_cache)) {
        left_cache.clear();
        right_cache.clear();
        sub_str += 1;
        success_sub_str = true;
      }
      left_p ++;
      right_p--;
    }

    // edge case
    int K = 0;
    if (success_sub_str) {
      if (left_p == right_p) {
        K = 1;
      } else {
        K = 0;
      }
    } else {
      K = 1;
    }

    return K + 2*sub_str;
  }

  bool compareLeftRightSubstr(vector<char>& left_cache, vector<char>& right_cache) {
    int length = right_cache.size();
    for (int i = 0; i < length; i++) {
      if (left_cache[i] != right_cache[length - 1 - i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sln;
  string s = "ghiabcdefhelloadamhelloabcdefghi";
  int result = sln.longestDecomposition(s);
  std::cout << "res: " << result << std::endl;

  return 0;
}
