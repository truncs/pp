#include <iostream>
#include <vector>

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

int main() {
  vector<int> test;
  vector<int> result(8);
  
  for (int i = 0; i < 8; ++i)
	{
	  test.push_back(i);
	  cout<<test[i]<<" ";
	}
  cout<<endl;
  prefix_sum(test, result);
  
  for (int i = 0; i < 8; ++i)
	{
	  cout<<result[i]<<" ";
	}
  cout<<endl;


}
