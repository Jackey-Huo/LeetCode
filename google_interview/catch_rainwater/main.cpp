#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int trap(vector<int>& height) {
    int total_slot = height.size();
    vector<int> complement = height;

    int idx = 0;
    // left to right
    while (idx < total_slot) {
      int cur_height = height[idx];
      bool catched = false;
      int right_slot = idx;
      for (int i = idx + 1; i < total_slot; i++) {
        int tmp_height = height[i];
        if (tmp_height >= cur_height) {
          catched = true;
          right_slot = i;
          break;
        }
      }

      if (catched) {
        for (int i = idx; i < right_slot; i++) {
          complement[i] = std::max(cur_height, complement[i]);
        }
        idx = right_slot;
      } else {
        idx ++;
      }
    }

    // right to left
    idx = total_slot - 1;
    while (idx > 0) {
      int cur_height = height[idx];
      bool catched =false;
      int left_slot = idx;
      for (int i = idx - 1; i >= 0; i--) {
        int tmp_height = height[i];
        if (tmp_height >= cur_height) {
          catched = true;
          left_slot = i;
          break;
        }
      }

      if (catched) {
        for (int i = idx; i > left_slot; i--) {
          complement[i] = std::max(cur_height, complement[i]);
        }
        idx = left_slot;
      } else {
        idx --;
      }
    }

    int water_count = 0;
    for (int i = 0; i < height.size(); i++) {
      water_count += (complement[i] - height[i]);
    }

    return water_count;
  }
};


int main() {
  vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
  Solution sln = Solution();
  int result = sln.trap(height);

  std::cout << "res: " << result << std::endl;

  return 0;
}
