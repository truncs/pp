#include "SpaceOptimizedQueue.h"


SpaceOptimizedQueue :: SpaceOptimizedQueue(int c) {
  soq_queue = list<int>(c, 0);
  capacity = c;
  initial_capacity = c;
  filled = 0;
  current = soq_queue.begin();

}


void SpaceOptimizedQueue:: enque(int value) {

  if (current == soq_queue.end()) {
	// Double the capacity 
	capacity = capacity*2;
	soq_queue.resize(capacity, 0);
	
  }
  
  *current = value;
  current += 1;
  filled += 1;

}


int SpaceOptimizedQueue :: deque() {
  if (current == soq_queue.begin())
	return 0;
  
  int value = soq_queue.front();
  soq_queue.pop_front();
  soq_queue.push_back(0);
  filled -= 1;
  
  if (filled < 0.25 * capacity) {
	int k = min(capacity/2, initial_capacity);
	soq_queue.resize(k);
  }
  

}

bool SpaceOptimizedQueue :: empty() {
  if (filled == 0)
	return true;
  else 
	return false;
}
