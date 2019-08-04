#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
  string licenseKeyFormatting(string S, int K) {
    const char* p_str = S.c_str();
    vector<char> keys;

    while (*p_str != '\0') {
      if (*p_str != '-') {
        keys.push_back(std::toupper(*p_str));
      }
      p_str ++;
    }

    vector<string> new_key_groups;
    while (keys.size() > K) {
      string cur_group;
      for (int i = 0; i < K; i++) {
        cur_group.push_back(keys.back());
        keys.pop_back();
      }
      new_key_groups.push_back(cur_group);
    }

    string group1;
    while (!keys.empty()) {
      group1.push_back(keys.back());
      keys.pop_back();
    }
    new_key_groups.push_back(group1);

    return generateNewKey(new_key_groups);
  }

  string generateNewKey(vector<string>& new_key_groups) {
    string result = new_key_groups.back();
    std::reverse(result.begin(), result.end());
    new_key_groups.pop_back();
    while (!new_key_groups.empty()) {
      string cur_group = new_key_groups.back();
      new_key_groups.pop_back();
      std::reverse(cur_group.begin(), cur_group.end());

      result += "-";
      result += cur_group;
    }
    return result;
  }
};
