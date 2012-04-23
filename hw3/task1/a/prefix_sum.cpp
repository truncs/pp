#include <iostream>
#include <vector>

using namespace std;

void prefix_sum(vector<int> & x, vector<int>& s) {

  int n = x.size();
  vector<int> y(n/2 + 1);

  if (n == 2)
	s[1] = x[1];

  else {
	for (int i = 1; i < n/2; ++i)
	  {
		y[i] = x[2*i -1] + x[2*i];
	  }
	vector<int> z(n/2 + 1);
	prefix_sum(y, z);
	for (int i = 1; i < n; ++i)
	  {
		if (i == 1)
		  s[1] = x[1];
		else if (i % 2 == 0)
		  s[i] = z[i/2];
		else
		  s[i] = z[(i - 1) / 2] + x[i];
			
	  }
  }

  return;
}

int main() {
  vector<int> test;
  vector<int> result(9);
  test.push_back(0);
  
  for (int i = 0; i < 9; ++i)
	{
	  test.push_back(1);
	  cout<<test[i]<<" ";
	}
  cout<<endl;
  prefix_sum(test, result);
  
  for (int i = 1; i < 9; ++i)
	{
	  cout<<result[i]<<" ";
	}
  cout<<endl;


}
