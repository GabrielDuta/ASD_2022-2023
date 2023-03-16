
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv[]) {
	fstream in, out;
	int n, m;

	in.open("input.txt", ios::in);
	out.open("output.txt", ios::out);
	if(in.fail() || out.fail()) {
		cout << "Impossibile aprire uno dei file" << endl;
		in.close();
		out.close();
		exit(1);
	}

	in >> n >> m;
	out << n + m << '\n';

	in.close();
	out.close();
    return 0;
}
