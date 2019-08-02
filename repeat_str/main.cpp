#include <string>
#include <iostream>


class Solution {
public:
  int repeatedStringMatch(std::string A, std::string B) {
    int len_a = A.length(), len_b = B.length();
    const char* a_str = A.c_str();
    const char* b_str = B.c_str();
    std::string result = A;
    int num = 1;
    while (true) {
      if (len_a * num < len_b) {
        result += A;
        num ++;
        continue;
      }

      if (len_a * num > (2*len_a + len_b)) {
        return -1;
      }

      if (result.find(B) != std::string::npos) {
        return num;
      } else {
        result += A;
        num ++;
      }
    }
  }

};


int main() {
  Solution sln = Solution();
  int num = sln.repeatedStringMatch(std::string("a"), std::string("aa"));
  std::cout << "num: " << num << std::endl;

  return 0;
}
