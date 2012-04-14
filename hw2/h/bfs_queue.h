#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <deque>
#include <cilk.h>
#include <cilk_mutex.h>

using namespace std;

class BfsQueue {
  vector<deque<int> > queues;
  int nseg;
  int p;
  int seg;
  cilk::mutex m;

public:
  BfsQueue(int p, int n);
  void enque(int i, int value);
  int deque(int p);
  void set_segment_size();
  int getSize();
};
