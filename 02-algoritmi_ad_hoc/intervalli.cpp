
#include <fstream>
#include <vector>
#include <cmath>
#include <utility>
#include <iostream>
using namespace std;

pair<int, int> intervallo(vector<pair<int, int>> vett, int t) {
    int max = 0, count = 0, n, nmax = 0;
    int first, second;
    int min = 0, diff, nmin;

    for(int i = 0; i < vett.size(); i++) {
        min = 0;
        second = vett[i].second;
        for(int j = 0; j < vett.size(); j++) {
            if(i != j) {
                first = vett[j].first;
                if(first < second && second < vett[j].second) {
                    min = 0;
                    j = vett.size();
                }
                else if(first > second) {
                    diff = first - second;
                    if(min = 0 || diff < min) {
                        min = diff;
                        nmin = second;
                    }
                }
            }
        }
        if(min > max) {
            max = min;
            nmax = nmin;
        }
    } 
    return make_pair(max, nmax);
}

int main(int argc, char * argv[]) {
	int n, n1, t;
    vector<pair<int, int>> vett;    

	ifstream in("input.txt");
	ofstream out("output.txt");

    in >> t;
    while(in >> n) {
        in >> n1;
        vett.push_back(make_pair(n, n1));
    }

    pair<int, int> res = intervallo(vett, t);

    if(res.first == 0)
        out << 0;
    else
        out << res.second << " " << res.second + res.first;

	in.close();
	out.close();
    return 0;
}