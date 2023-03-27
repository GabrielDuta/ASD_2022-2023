
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const int max_length = 8;
int dp[4][8]; 

int lcs(int pos_lettera, string sequenza, int next);

int main(int argc, char * argv[]) {

  string seq1 = "AAAATTGA";
  string seq2 = "TAAAGATA";

  int length = 7;
  int i, j;
  int i_lettere = length - 1;
  int maxsofar = 0;

  dp[0][length] = 0;
  dp[1][length] = 0;
  dp[2][length] = 0;
  dp[3][length] = 0;
  switch (seq1[length]) {
    case 'A': dp[0][length] = length + 1;
      break;
    case 'C': dp[1][length] = length + 1;
      break;
    case 'G': dp[2][length] = length + 1;
      break;
    case 'T': dp[3][length] = length + 1;
      break;
  }

  for(i = seq1.length() - 2; i >= 0; i--) {
    dp[0][i] = dp[0][i + 1];
    dp[1][i] = dp[1][i + 1];
    dp[2][i] = dp[2][i + 1];
    dp[3][i] = dp[3][i + 1];

    switch (seq1[i_lettere]) {
      case 'A': dp[0][i] = i + 1;
        break;
      case 'C': dp[1][i] = i + 1;
        break;
      case 'G': dp[2][i] = i + 1;
        break;
      case 'T': dp[3][i] = i + 1;
        break;
    }
    i_lettere -= 1;
  }


  for(i = 0; i < seq2.length(); i++)
    maxsofar = max(maxsofar, lcs(i, seq2, 0));

  cout << maxsofar << endl;
/* 
  for(i = 0; i < 4; i++) {
    for(j = 0; j < length; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
 */

	// ifstream in("input.txt");
	// ofstream out("output.txt");

	// in.close();
	// out.close();
    return 0;
}

int lcs(int pos_lettera, string sequenza, int next) {
  if(next >= max_length)
    return 0;

  int i, maxsofar = 0;
  int next_pos;
  switch(sequenza[pos_lettera]) {
    case 'A': next_pos = dp[0][next];
      break;
    case 'C': next_pos = dp[1][next];
      break;
    case 'G': next_pos = dp[2][next];
      break;
    case 'T': next_pos = dp[3][next];
      break;
  }

  if(next_pos <= pos_lettera)
    return 0;
  if(next >= max_length)
    return 1;

  cout << sequenza[pos_lettera] << next_pos << endl;

  for(i = pos_lettera + 1; i < sequenza.length(); i++)
    maxsofar = max(maxsofar, lcs(i, sequenza, next_pos + 1));
  return maxsofar + 1;

}
