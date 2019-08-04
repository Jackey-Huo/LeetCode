#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
  int movesToMakeZigzag(vector<int>& nums) {
    // try condition 1
    int try1 = tryCond1(nums);

    // try condition 2
    int try2 = tryCond2(nums);

    return (try1 < try2 ? try1 : try2);
  }

  int tryCond1(vector<int>& num) {
    vector<int> num1 = num;
    int op = 0;
    for (int i = 0; i < num1.size(); i++) {
      if (i % 2 == 1) {
        if (num1[i - 1] <= num1[i]) {
          op += (num1[i] - num1[i - 1] + 1);
          num1[i] = num1[i - 1] - 1;
        }
        if (i+1 < num1.size() && num1[i+1] <= num1[i]) {
          op += (num1[i] - num1[i + 1] + 1);
          num1[i] = num1[i+1] - 1;
        }
      }
    }

    return op;
  }


  int tryCond2(vector<int>& num) {
    vector<int> num2 = num;
    int op = 0;
    for (int i = 0; i < num2.size(); i++) {
      if (i % 2 == 0) {
        if (i - 1 >= 0 && num2[i-1] <= num2[i]) {
          op += (num2[i] - num2[i - 1] + 1);
          num2[i] = num2[i - 1] - 1;
        }
        if (i + 1 < num2.size() && num2[i+1] <= num2[i]) {
          op += (num2[i] - num2[i + 1] + 1);
          num2[i] = num2[i + 1] - 1;
        }
      }
    }

    return op;
  }

};

int main() {
  vector<int> nums = {9, 6, 1, 6, 2};
  Solution sln;
  int result = sln.movesToMakeZigzag(nums);
  std::cout << "res: " << result << std::endl;

  return 0;
}
