#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
using namespace std;

vector<pair<vector<int>, bool>> grafo;

void print_graph(int n);
int count_ragg(int start, int);
void restart(int n);
void print(int [], int);

int main() {
  	int N, M;

	ifstream in("input.txt");
	ofstream out("output.txt");

  	in >> N >> M;
  	grafo.resize(N);

	for(pair<vector<int>, bool> v : grafo)
		v.second = false;
  	for(int j=0; j<M; j++) {
 		int from, to;
    	in >> from >> to;
		grafo[from].first.push_back(to);
		grafo[to].first.push_back(from);
  	}

	print_graph(N);

	int max = 0;
	for(int i = 0; i < N; i++) {
		restart(N);
		int temp = count_ragg(i, N);
		if(temp > max)
			max = temp;
	}

	out << max;

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

int count_ragg(int start, int n) {
	int vett[n];
	int prec = start, eval;
	bool counted = false;
	queue<int> coda;

	for(int i = 0; i < n; i++)
		vett[i] = -1;

	coda.push(start);
	vett[start] = 0;
	while(!coda.empty()) {
		eval = coda.front();
		coda.pop();

		if(!grafo[eval].second) {
			grafo[eval].second = true;
		
    		for(int v: grafo[eval].first)
				if(!grafo[v].second) {
					coda.push(v);
					if(vett[v] == -1 || vett[eval] + 1 < vett[v])
						vett[v] = vett[eval] + 1;
				}
		}
	}
	return vett[eval];
}

void restart(int n) {
	for(int i = 0; i < n; i++)
		grafo[i].second = false;
}

void print(int vett[], int n) {
	for(int i = 0; i < n; i++)
		cout << vett[i] << " ";
	cout << endl;
}