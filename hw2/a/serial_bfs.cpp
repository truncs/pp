#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

void serial_bfs(int source_index, int n, vector<vector<int> > & tau){

  queue<int> bfs_queue;
  vector<int> d;

  for (int i = 0; i <= n; i++ ) {
	d.push_back(-1);
  }
  
  d[source_index] = 0;
  
  bfs_queue.push(source_index);

  while (!bfs_queue.empty()) {
	int u  = bfs_queue.front();
	bfs_queue.pop();
	for (int j = 0; j < tau[u].size(); j++) {

	  int v = tau[u][j];

	  if (d[v] == -1) {
		d[v] = d[u] + 1;
		bfs_queue.push(v);
	  }
	}

  }
  
  long int checksum = 0;
  int max_depth = 0;

  for (int i = 1; i <= n; i++ ) {
	if (max_depth < d[i]){
	  max_depth = d[i];
	}

	if (d[i] == -1) 
	  checksum += n;
	else
	  checksum += d[i];
  }

  cout <<max_depth << " "<< checksum<<endl;
}


int main(){
  int n;
  int m;
  int r;
  

  string string_n;
  getline(cin, string_n);
  vector<string> tokens;
  istringstream iss(string_n);
  copy(istream_iterator<string>(iss),
	   istream_iterator<string>(),
	   back_inserter<vector<string> >(tokens));
  
  n = atoi(tokens[0].c_str());
  m = atoi(tokens[1].c_str());
  r = atoi(tokens[2].c_str());
  

  vector<vector<int> > tau(n + 1);
  

  for (int i = 0; i < m; i++) {

	string temp;
	vector<string> tokenized;
	getline(cin, temp);

	stringstream iss(temp);
	copy(istream_iterator<string>(iss),
		 istream_iterator<string>(),
		 back_inserter<vector<string> >(tokenized));

	int u = atoi(tokenized[0].c_str());
	int v = atoi(tokenized[1].c_str());

	tau[u].push_back(v);
  }

  for (int j = 0; j < r ; j++) {
	string source_string;
	getline(cin, source_string);
	int source_index = atoi(source_string.c_str());
	
	serial_bfs(source_index, n, tau);

  }
  


  
}

