#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void prefix_sum(vector<int> & x, vector<int>& s) {

  int n = x.size();
  vector<int> y(n/2);

  if (n == 1)
	s[0] = x[0];

  else {
	for (int i = 0; i < n/2; ++i)
	  {
		y[i] = x[2*i] + x[2*i + 1];
	  }
	vector<int> z(n/2);
	prefix_sum(y, z);
	for (int i = 0; i < n; ++i)
	  {
		if (i == 0)
		  s[0] = x[0];
		else if (i % 2 != 0)
		  s[i] = z[(i - 1)/2];
		else
		  s[i] = z[(i - 2) / 2] + x[i];
			
	  }
  }

  return;
}



int par_partition(vector<int>& A, int q, int r, int x) {
  int n = r - q + 1;
  if (n == 1)
	return q;

  vector<int> B(n), lt(n), gt(n);
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

  

  vector<int> new_lt(n);
  vector<int> new_gt(n);
  
  prefix_sum(lt, new_lt);
  prefix_sum(gt, new_gt);

  int k = q + new_lt[n - 1];
  A[k] = x;

  for (int i = 0; i < n; ++i)
	{
	  if (B[i] < x)
		A[q + new_lt[i] - 1] = B[i];
	  else if (B[i] > x)
		A[k + new_gt[i]] = B[i];
	}

  return k;

}



void par_randomized_qsort(vector<int>& A, int q, int r) {
  //cout<<"r :"<<r<<" q: "<<q<<endl;
  int n = r - q + 1;
  if (n <= 5) {
	// Insertion sort
	// Reference CLRS 2.1
    //cout<<"Insertion Sort with n :"<<n<<endl;	
	for (int j = q + 1; j <= r; ++j)
	  {
		int key = A[j];
//        cout<<"key: "<<key<<endl;
		int i = j - 1;
		
		while (i >= q && A[i] > key) {
		  A[i + 1] = A[i];
		  i = i - 1;
		}
		
		A[i + 1] = key;

	  }

  }
  else {
	int k = 0;
	while (max(r - k, k - q) > 3*n/4) {
	  int rand_number = q  + (rand() % (n));
	  int x = A[rand_number];
	  k = par_partition(A, q, r, x);
     // cout<<"Testing on pivot "<<A[k]<<endl;
     // for(int i = 0; i < A.size(); i++) {
     //   cout<<A[i]<<endl;
     // }
      
    //    cout<<"-----------"<<endl;
	}
    //cout<<"Found a good pivot"<<A[k]<<endl;	
	par_randomized_qsort(A, q, k - 1);
	par_randomized_qsort(A, k + 1, r);
	
	
  }
	
  

}

int main() {

    int arr[] = {9, 5, 7, 11, 1, 3, 8, 14, 4, 21};
    vector<int> a (arr, arr + 10);
    par_randomized_qsort(a, 0, 9);
    for(int i = 0; i < 10; i++) {
        cout<<a[i]<<endl;
    }
    //cout<<par_partition(a, 0,9, 8)<<endl; 
    return 0;
}
