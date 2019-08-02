#include <vector>
#include <list>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
  int kEmptySlots(vector<int>& bulbs, int K) {
    map<int, int>  flower; // <num, day>

    for (int i = 0; i < bulbs.size(); i++) {
      int flow_num = bulbs[i];
      flower[flow_num] = i;
      auto flow_num_iter = flower.find(flow_num);
      if (flow_num_iter != flower.begin()) {
        int new1 = flow_num - (std::prev(flow_num_iter, 1))->first - 1;
        if (new1 == K) {
          return i+1;
        }
      }
      if (std::next(flow_num_iter, 1) != flower.end()) {
        int new2 = std::next(flow_num_iter, 1)->first - flow_num - 1;
        if (new2 == K) {
          return i+1;
        }
      }
    }

    return -1;
  }

};

int main() {
  vector<int> bulbs = {1, 3, 2};
  Solution sln = Solution();
  int res = sln.kEmptySlots(bulbs, 1);
  std::cout << "res: " << res << std::endl;

  return 0;
}
