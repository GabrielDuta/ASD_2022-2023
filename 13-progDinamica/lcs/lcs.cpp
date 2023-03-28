
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int lcs(int n, int m);

#define MAXLENGTH 10001
int dp[MAXLENGTH][MAXLENGTH];
string seq1, seq2;

int main(int argc, char * argv[]) {
  int n, m;
  int i, j;

  ifstream in("input.txt");
	ofstream out("output.txt");
  in >> seq1 >> seq2;
  n = seq1.length(); m = seq2.length();
  for(i = 0; i < n; i ++)
    for(j = 0; j < m; j++) {
      if(i == 0 || j == 0)
        dp[i][j] = 0;
      else
        dp[i][j] = -1;
    }

  out <<  lcs(n - 1, m - 1) << endl;

	in.close();
	out.close();
  return 0;
}

int lcs(int n, int m) {
  if(n == -1 || m == -1)
    return 0;
  if(dp[n][m] > 0)
    return dp[n][m];
  
  if(seq1[n] == seq2[m])
    dp[n][m] = lcs(n - 1, m - 1) + 1;
  else
    dp[n][m] = max(lcs(n - 1, m), lcs(n, m - 1));
  return dp[n][m];
}










