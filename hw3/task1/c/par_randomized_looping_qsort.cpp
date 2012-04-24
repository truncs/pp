#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void par_randomized_qsort(vector<int>& A, int q, int r) {
  int n = r - q + 1;
  if (n <= 30) {
	// Insertion sort
	// Reference CLRS 2.1
	
	for (int j = q + 1; j < n; ++j)
	  {
		int key = A[j];
		int i = j - 1;
		
		while (i > q && A[i] > key) {
		  A[i + 1] = A[i];
		  i = i - 1;
		}
		
		A[i + 1] = key;

	  }

  }
  else {
	k = 0;
	while (max(r - k, k - q) > 3*n/4) {
	  int rand_number = k  + (rand() % (n));
	  int x = A[rand_number];
	  int k = par_partition(A, q, r);
	}
	
	par_randomized_qsort(A, q, k - 1);
	par_randomized_qsort(A, k + 1, r);
	
	
  }
	
  

}
