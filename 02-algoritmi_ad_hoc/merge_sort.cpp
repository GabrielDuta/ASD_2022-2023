
#include <fstream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

void merge_sort(vector<int> & vett, int start, int end);
void merge(vector<int> & vett, int start, int mid, int end);

int main(int argc, char * argv[]) {
	int n1, n2, t;
    vector<int> vett;    

	ifstream in("input.txt");
	ofstream out("output.txt");

    in >> t;
    for(int i = 0; i < t; i++) {
        in >> n1;
        in >> n2;
        while(n1 < n2) {
            vett.push_back(n1);
            n1++;
        }
    }

	merge_sort(vett, 0, vett.size() - 1);

	in.close();
	out.close();
    return 0;
}

void merge_sort(vector<int> & vett, int start, int end) {
    int mid = (start + end) / 2;

    if(start < end) {
        merge_sort(vett, start, mid);
        merge_sort(vett, mid + 1, end);
        merge(vett, start, mid, end);
    }
}

void merge(vector<int> & vett, int start, int mid, int end) {
    int i = start, j = mid + 1;
    int temp[end - start];
    int s = 0;

    while(i <= mid && j <= end) {
        if(vett[i] < vett[j]) {
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