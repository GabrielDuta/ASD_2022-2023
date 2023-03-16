
#include <fstream>
#include <vector>
#include <utility>
using namespace std;

int contaPassi(vector<int>);
int calcolaCosto(vector<int>);
int search(vector<int>, int);

int main(int argc, char * argv[]) {
	int n;
    int tmp;
	int passi, costo;
    vector<int> vett1;
    vector<int> vett2;


	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n;
    while(in >> tmp) {
        vett1.push_back(tmp);
        vett2.push_back(tmp);
	}

	passi = contaPassi(vett1);
	costo = calcolaCosto(vett2); 

	out << passi << " " << costo << endl;

	in.close();
	out.close();
    return 0;
}

int contaPassi(vector<int> vett) {
	int counter = 0;
	int sw, ichanged, changed;

	for(int i = 1; i <= vett.size(); i++){
		sw = search(vett, i);
		ichanged = search(vett, sw + 1);
		changed = vett[ichanged];

		if(sw + 1 != i){
			vett[sw] = changed;
			vett[ichanged] = i;
			counter++;
			i--;
		}	
	}
	return counter;
}
int calcolaCosto(vector<int> vett) {
	int costo = 0;

	return costo;
}

int search(vector<int> vett, int x) {
	for(int i = 0; i < vett.size(); i++)
		if(vett[i] == x)
			return i;
	return -1;
}