
#include <fstream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

void merge_sort(vector<pair<int, int>> & vett, int start, int end);
void merge(vector<pair<int, int>> & vett, int start, int mid, int end);


pair<int, int> intervallo(vector<pair<int, int>> vett, int t) {
    int max = 0, nmax = 0;
    int ncompare = vett[0].second;
    int diff;

    for(int i = 1; i < vett.size(); i++) {
        if(ncompare >= vett[i].first) {
            if(ncompare < vett[i].second)
                ncompare = vett[i].second;
        }
        else {
            diff = vett[i].first - ncompare;
            if(diff > max) {
                max = diff;
                nmax = ncompare;
            }
            ncompare = vett[i].second;
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

    merge_sort(vett, 0, vett.size() - 1);

    pair<int, int> res = intervallo(vett, t);

    if(res.first == 0)
        out << 0;
    else
        out << res.second << " " << res.second + res.first;

	in.close();
	out.close();
    return 0;
}

void merge_sort(vector<pair<int, int>> & vett, int start, int end) {
    int mid = (start + end) / 2;

    if(start < end) {
        merge_sort(vett, start, mid);
        merge_sort(vett, mid + 1, end);
        merge(vett, start, mid, end);
    }
}

void merge(vector<pair<int, int>> & vett, int start, int mid, int end) {
    int i = start, j = mid + 1;
    pair<int, int> temp[end - start];
    int s = 0;

    while(i <= mid && j <= end) {
        if(vett[i].first < vett[j].first) {
            temp[s] = vett[i];
            i++;
        }
        else {
            temp[s] = vett[j];
            j++;
        }
        s++;
    }
    while(i <= mid) {
        temp[s] = vett[i];
        i++;
        s++;
    }
    while(j <= end) {
        temp[s] = vett[j];
        j++;
        s++;
    }
    for(s = start; s <= end; s++)
        vett[s] = temp[s - start];
}