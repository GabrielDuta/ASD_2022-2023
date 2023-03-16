
#include <iostream>
#include <fstream>
using namespace std;

int sottoseq(int s[], int n) {
	int maxsofar = 0;
	int j, sum = 0;
	for(int i = 0; i < n; i++) {
		sum += s[i];
		if(sum < 0)
			sum = 0;
		if(sum > maxsofar)
			maxsofar = sum;
	}
	return maxsofar;
}

int main(int argc, char * argv[]) {
	int n;

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n;
	int s[n];
	for(int i = 0; i < n; i++)
		in >> s[i];

	out << sottoseq(s, n);

	in.close();
	out.close();
    return 0;
}
