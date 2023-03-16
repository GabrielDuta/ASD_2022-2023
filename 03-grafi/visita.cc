#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector<pair<vector<int>, bool>> grafo;

void print_graph(int n);
int count_ragg(int start);

int main() {
  	int N, M, search;

	ifstream in("input.txt");
	ofstream out("output.txt");

  	in >> N >> M >> search;
  	grafo.resize(N);

	for(pair<vector<int>, bool> v : grafo)
		v.second = false;
  	for(int j=0; j<M; j++) {
 		int from, to;
    	in >> from >> to;
		grafo[from].first.push_back(to);
		grafo[from].second = false;
  	}

	out << count_ragg(search);	

  return 0;
}

void print_graph(int n) {

  	for(int i=0; i<n; i++) {
    	cout << "Nodo " << i << " ha " << grafo[i].first.size() <<" vicini" << endl;
    	for(int v: grafo[i].first) {
    		cout << "  " << v << endl;
   		}
  	}
	
}

int count_ragg(int start) {
	int count = 0;
	int eval;
	queue<int> coda;

	coda.push(start);
	while(!coda.empty()) {
		eval = coda.front();
		coda.pop();
		if(!grafo[eval].second) {
			grafo[eval].second = true;
			count++;
		
    		for(int v: grafo[eval].first)
				if(!grafo[v].second)
					coda.push(v);
		}
	}
	return count;
}