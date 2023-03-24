
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

#define MAXC 100005
#define MAXN 1005
int n;
int c;
int peso[MAXN], profitto[MAXN];
int dp[MAXC];

int main(int argc, char * argv[]) {
  int i, j;

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> c >> n;
  for(i = 1; i <= n; i++)
    in >> peso[i] >> profitto[i];
    
  for(i = 0; i <= n; i++)
    dp[i] = 0;

  for(i = 1; i <= n; i++) {
    for(j = c - peso[i]; j >= 0; j--) {
      dp[j + peso[i]] = max(dp[j + peso[i]], dp[j] + profitto[i]);
    }   
  }

  out << *max_element(dp, dp + c + 1) << endl;

	in.close();
	out.close();
  return 0;
}
