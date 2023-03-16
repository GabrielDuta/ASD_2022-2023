
#include <fstream>
#include <vector>
using namespace std;

int sottomat(vector<vector<int>> mat, int rig, int col) {
    int maxsofar = 0;
    int i, j, j1, j2;
    int sum = 0;
    int prefix[rig][col];

    for(i = 0; i < rig; i++) {
        for(j = 0; j < col; j++){
            if(j == 0)
                prefix[i][j] = mat[i][j];
            else
                prefix[i][j] = mat[i][j] + prefix[i][j - 1];
        }
    }
    

    for(j1 = 0; j1 < col; j1++) {
        for(j2 = j1; j2 < col; j2++) {
            for(i = 0; i < rig; i++) {
                if(j1 == 0)
                    sum += prefix[i][j2];
                else
                    sum += prefix[i][j2] - prefix[i][j1 - 1];
                if(sum < 0)
                    sum = 0;
                if(sum > maxsofar)
                    maxsofar = sum;
            }
            sum = 0;
        }
    }
    return maxsofar;
}

int main(int argc, char * argv[]) {
	int rig, col;
	int i, j, temp;
	vector<vector<int>> mat;

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> rig >> col;
	for(i = 0; i < rig; i++) {
	    vector<int> t;
	    for(j = 0; j < col; j++) {
	        in >> temp;
	        t.push_back(temp);
	    }
	    mat.push_back(t);
	}

    out << sottomat(mat, rig, col);

	in.close();
	out.close();
    return 0;
}
