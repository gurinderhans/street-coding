#include <iostream>
#include <vector>

using namespace std;

class minheap {
  private:
    vector<int> _arr;
  public:
    minheap() {}

    int parentIndex(int fromIdx) {
      return (fromIdx - 1)/2;
    }

    int leftChildIdx(int fromIdx) {
      return (fromIdx*2)+1;
    }
    int rightChildIdx(int fromIdx) {
      return (fromIdx*2)+2;
    }

    void swap(int i, int j) {
      int t=_arr[i];
      _arr[i]=_arr[j];
      _arr[j]=t;
    }

    void insert(int el) {
      // insert element at end, then bubble
      // it up to its correct position
      _arr.push_back(el);
      int curr_idx = _arr.size()-1;
      int pidx=parentIndex(curr_idx);
      while(pidx > -1 && _arr[pidx] > _arr[curr_idx]) {
        swap(curr_idx, pidx);
        curr_idx = pidx;
        pidx=parentIndex(curr_idx);
      }
    }

    void removeAt(int idx) {
      // 1. swap element at `idx` with the last element
      // 2. remove the last element
      // 3. heapify down from node at `idx` till the heap
      //    property is restored!
      //    - look at node at `curr_idx = idx` and see if
      //      it is less than the left child

      swap(idx, _arr.size()-1);
      _arr.pop_back();

      int curr_idx = idx;
      int li = leftChildIdx(curr_idx);
      int ri = rightChildIdx(curr_idx);
      while(li < _arr.size() && (_arr[curr_idx] > _arr[li] || _arr[curr_idx] > _arr[ri])) {
        int minChildIdx = li;
        if (_arr[minChildIdx] > ri) {
          minChildIdx = ri;
        }

        swap(curr_idx, minChildIdx);
        curr_idx = minChildIdx;
        li = leftChildIdx(curr_idx);
        ri = rightChildIdx(curr_idx);
      }
    }

    int front() {
      return _arr[0];
    }
    
    void _print() {
      for (int i : _arr) {
        cout << i << " ";
      }
      cout << endl;
    }
};

int main() {
  minheap h;
  h.insert(3);
  h.insert(2);
  h.insert(4);
  h.insert(1);

  h._print();

  h.removeAt(0);

  h._print();

  return 0;
}
