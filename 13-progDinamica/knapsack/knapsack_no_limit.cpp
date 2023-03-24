
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
int padre[MAXC];

int main(int argc, char * argv[]) {
  int i, j, f;
  int maxsofar = 0;

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> c >> n;
  for(i = 1; i <= n; i++)
    in >> peso[i] >> profitto[i];
    
  for(i = 0; i <= n; i++)
    dp[i] = 0;

  for(i = 1; i <= c; i++) {
    maxsofar = 0;
    for(j = 1; j <= n; j++) {
      if(peso[j] <= i)
        for(f = i - peso[j]; f >= 0; f--) 
          if(maxsofar < dp[f] + profitto[j]) {
            maxsofar = dp[f] + profitto[j];
            padre[i] = j;
          }
      dp[i] = maxsofar;
    }
  }

  for(i = 0; i <= c; i++)
    cout << dp[i] << " ";
  cout << endl;

  //out << *max_element(dp, dp + c + 1) << endl;
  out << dp[c] << endl;

  int pd = padre[c];
  while(pd != 0) {
    cout << pd << " ";
    c -= peso[pd];
    pd = padre[c];
  }
  cout << endl;

	in.close();
	out.close();
  return 0;
}

