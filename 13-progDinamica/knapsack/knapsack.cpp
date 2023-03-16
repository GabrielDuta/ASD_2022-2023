
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

#define MAXC 100005
#define MAXN 1005
int n;
int c;
int peso[MAXN], profitto[MAXN];
//int dp[MAXN][MAXC];
int dp2[MAXC];

int main(int argc, char * argv[]) {
  int i, j;

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> c >> n;
  for(i = 1; i <= n; i++)
    in >> peso[i] >> profitto[i];
    
  for(i = 0; i <= n; i++)
    dp2[i] = 0;

  /*
  for(i = 0; i <= n; i++)
    dp[i][0] = 0;
  for(i = 0; i <= c; i++)
    dp[0][i] = 0;

  for(i = 1; i <= n; i++) {
    for(j = 1; j <= c; j++) {
      if(peso[i] <= j)
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - peso[i]] + profitto[i]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  */

  for(i = 1; i <= n; i++) {
    for(j = c - peso[i]; j >= 0; j--) {
      dp2[j + peso[i]] = max(dp2[j + peso[i]], dp2[j] + profitto[i]);
    }   
  }

  out << *max_element(dp2, dp2 + c + 1) << endl;

	in.close();
	out.close();
  return 0;
}
