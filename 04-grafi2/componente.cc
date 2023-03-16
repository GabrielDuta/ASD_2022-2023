#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <stack>
using namespace std;

vector<vector<int>> grafo;

void print_graph(int n);
int scc(int n);
stack<int> top_sort(int n);
void ts_dfs(int nodo, bool visited[], stack<int> & s);
vector<vector<int>> transpose(int n);
int cc(stack<int> s, int n);
int ccdfs(int counter, int node, int id[], int count);

int main() {
  	int N, M, search;

	ifstream in("input.txt");
	ofstream out("output.txt");

  	in >> N >> M;
  	grafo.resize(N);

  	for(int j=0; j<M; j++) {
 		int from, to;
    	in >> from >> to;
		grafo[from].push_back(to);
  	}

	out << scc(N);	

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

int scc(int n) {
	stack<int> s = top_sort(n);
	grafo = transpose(n);
	return cc(s, n);
}

stack<int> top_sort(int n) {
	stack<int> s;
	bool visited[n];
	int i = 0;

	for(i = 0; i < n; i++)
		visited[i] = false;

	for(i = 0; i < n; i++) {
		if(!visited[i])
			ts_dfs(i, visited, s);
	}
	return s;
}

void ts_dfs(int nodo, bool visited[], stack<int> & s) {
	visited[nodo] = true;
	for(int v : grafo[nodo]) {
		if(!visited[v])
			ts_dfs(v, visited, s);
	}
	s.push(nodo);
}

vector<vector<int>> transpose(int n) {
	vector<vector<int>> gt;
	gt.resize(n);

	for(int i = 0; i < n; i++) {
		for(int v : grafo[i])
			gt[v].push_back(i);
	}
	return gt;
}

int cc(stack<int> s, int n) {
	int id[n];
	int counter = 0;
	int u;
	int max = 0;
	int count;

	for(int i = 0; i < n; i++)
		id[i] = 0;
	while(!s.empty()) {
		u = s.top();
		s.pop();
		if(id[u] == 0) {
			counter++;
			count = ccdfs(counter, u, id, 1);
			max = (count > max ? count : max);
		}
	}
	return max;
}

int ccdfs(int counter, int node, int id[], int count) {
	id[node] = counter;
	for(int v : grafo[node]) {
		if(id[v] == 0)
			count += ccdfs(counter, v, id, 1);
	}
	return count;
}