#include <iostream>
#include <vector>

using namespace std;

int par_partition(vector<int>& A, int q, int r, int x) {
  int n = r - q + 1;
  if (n == 1)
	return q;

  vector<int> B(n -1), lt(n - 1), gt(n - 1);
  for (int i = 0; i < n; ++i)
	{
	  B[i] = A[q + i];
	  if (B[i] < x)
		lt[i] = 1;
	  else 
		lt[i] = 0;
	  
	  if (B[i] > x)
		gt[i] = 1;
	  else
		gt[i] = 0;
	}

  

  vector<int> new_lt(n - 1);
  vector<int> new_gt(n - 1);

  
  // TODO Does this make sense 
  
  lt.push_front(0);
  gt.push_front(0);
  
  par_prefix_sum(&lt, &new_lt);
  par_prefix_sum(&gt, &new_gt);

  

  k = q + new_lt[n - 1];
  A[k] = x;

  for (int i = 0; i < n; ++i)
	{
	  if (B[i] < x)
		A[q + new_lt[i] - 1] = B[i];
	  else if (B[i] > x)
		A[k + gt[i]] = B[i];
	}

  return k;

}
