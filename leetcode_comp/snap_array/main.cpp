#include <vector>
#include <map>
using namespace std;


class SnapshotArray {
public:
  SnapshotArray(int length) {
    snap_id_ = 0;
    length_ = length;
  }

  void set(int index, int val) {
    array_[index] = val;
  }

  int snap() {
    snaps_.push_back(array_);
    return snap_id_ ++;
  }

  int get(int index, int snap_id) {
    map<int, int>& target_snap = snaps_[snap_id];
    return (target_snap.find(index) == target_snap.end() ? 0 : target_snap[index]);
  }

private:
  vector<map<int, int>> snaps_;
  map<int, int>         array_;
  int snap_id_;
  int length_;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
