#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> result = digits;
    if (result.empty()) {
      result.push_back(1);
      return result;
    }

    int carry = 1;
    for (int i = result.size() - 1; i >= 0; i--) {
      int num = result[i] + carry;
      result[i] = num % 10;
      carry = num / 10;
    }
    if (carry > 0) {
      result.insert(result.begin(), carry);
    }

    return result;
  }
};
