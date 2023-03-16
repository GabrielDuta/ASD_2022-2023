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
void ts_stack(int nodo, bool visited[], stack<int> & s);

int main() {
  	int N, M, search;
    stack<int> s;

	ifstream in("input.txt");
	ofstream out("output.txt");

  	in >> N >> M;
  	grafo.resize(N);

  	for(int j=0; j<M; j++) {
 		int from, to;
    	in >> from >> to;
		grafo[from].push_back(to);
  	}

    s = top_sort(N);
    while(!s.empty()) {
        out << s.top() << " ";
        s.pop();
    }

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

stack<int> top_sort(int n) {
    stack<int> s;
    bool visited[n];
    int i;

    for(i = 0; i < n; i++)
        visited[i] = false;
    for(i = 0; i < n; i++) {
        if(!visited[i]) {
            ts_stack(i, visited, s);
        }
    }
    return s;
}

void ts_stack(int nodo, bool visited[], stack<int> & s) {
    visited[nodo] = true;
    for(int v : grafo[nodo])
        if(!visited[v])
            ts_stack(v, visited, s);
    s.push(nodo);
}