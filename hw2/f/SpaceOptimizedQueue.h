#include <list>


using namespace std;

class SpaceOptimizedQueue {
  list<int> soq_queue
;
  list<int> :: iterator current;
  int filled;
  int capacity;
  
public:
  SpaceOptimizedQueue(int capacity);
  void enque(int);
  int deque();
  

};
