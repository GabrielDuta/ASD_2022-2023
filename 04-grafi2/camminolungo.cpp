#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <stack>
using namespace std;

vector<vector<int>> grafo;

void print_graph(int n);
int camminolungo(int n);
int visit(int i, int visited[]);

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

    out << camminolungo(N);

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

int camminolungo(int n) {
    int visited[n];
    int i;
    int max = -1, tmp;

    for(i = 0; i < n; i++)
        visited[i] = -1;
    for(i = 0; i < n; i++) {
        if(visited[i] == -1) {
            tmp = visit(i, visited);
            max = max < tmp ? tmp : max; 
        }
    }
    return max;
}

int visit(int i, int visited[]) {
    int max = -1;
    int tmp;

    if(visited[i] == -1) {
        for(int v : grafo[i]) {
            tmp = visit(v, visited);
            max = tmp > max ? tmp : max;
        }
        max++;
        visited[i] = max;
    }
    return visited[i];
}