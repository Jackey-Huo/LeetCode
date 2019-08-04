#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return result;
    }

    int width = matrix[0].size(), height = matrix.size();
    vector<vector<bool>> matrix_map(height);
    for (vector<bool>& line : matrix_map) {
      line.assign(width, false);
    }

    int x = 0, y = 0;
    char direction = 'r';
    for (int i = 0; i < width*height; i++) {
      result.push_back(matrix[y][x]);
      matrix_map[y][x] = true;
      computeNextIdx(x, y, matrix_map, height, width, direction);
    }

    return result;
  }

  void computeNextIdx(int& x, int& y, vector<vector<bool>>& map,
      int height, int width, char& direction) {
    bool top    = (y-1 < 0       ? true : map[y-1][x]);
    bool bottom = (y+1 >= height ? true : map[y+1][x]);
    bool left   = (x-1 < 0       ? true : map[y][x-1]);
    bool right  = (x+1 >= width  ? true : map[y][x+1]);
    if (direction == 'r') {
      if (!right) {
        x = x + 1;
        return;
      } else {
        direction = 'b';
        y = y+1;
        return;
      }
    } else if (direction == 'b') {
      if (!bottom) {
        y = y + 1;
        return;
      } else {
        direction = 'l';
        x = x - 1;
        return;
      }
    } else if (direction == 'l') {
      if (!left) {
        x = x - 1;
        return;
      } else {
        direction = 't';
        y = y - 1;
        return;
      }
    } else if (direction == 't') {
      if (!top) {
        y = y - 1;
        return;
      } else {
        direction = 'r';
        x = x + 1;
        return;
      }
    }
  }
};
