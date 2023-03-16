#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
using namespace std;

vector<vector<int>> grafo;

pair<int, int> cammini(int start, int, int);

int main() {
  	int N, M;
	int start, end;

	ifstream in("input.txt");
	ofstream out("output.txt");

  	in >> N >> M >> start >> end;
  	grafo.resize(N);

  	for(int j=0; j<M; j++) {
 		int from, to;
    	in >> from >> to;
		grafo[from].push_back(to);
  	}

	pair<int, int> res = cammini(start, end, N);

	out << res.second << " " << res.first;

  return 0;
}

void print_graph(int n) {

  	for(int i=0; i<n; i++) {
    	cout << "Nodo " << i << " ha " << grafo[i].size() <<" vicini" << endl;
    	for(int v: grafo[i]) {
    		cout << "  " << v << endl;
   		}
  	}
	
}

pair<int, int> cammini(int start, int end, int n) {
	int dist[n];
	int parc[n];
	int eval, prec = start;
	queue<int> q;
	
	for(int i = 0; i < n; i++) {
		dist[i] = -1;
		parc[i] = -1;
	}
	dist[start] = 0;
	parc[start] = 1;
	
	q.push(start);
	
	while(!q.empty()) {
		eval = q.front();
		q.pop();
		cout << eval << endl;

		for(int v : grafo[eval]) {
			if(dist[v] == -1) {
				dist[v] = dist[eval] + 1;
				parc[v] = parc[eval];
				q.push(v);
			}
			else if(dist[v] == dist[eval] + 1)
				parc[v] += parc[eval];
			else if(dist[eval] + 1 < dist[v]) {
				dist[v] = dist[eval] + 1;
				parc[v] = parc[eval];
			}
			cout << v << " " << parc[v] << endl;
		} 	
	}
	return make_pair(parc[end], dist[end]);
}