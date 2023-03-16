
#include <fstream>

using namespace std;

#define MAX 30
void count(int i);
void pilloleRec(int intere, int mezze);

int n;
long long int dp[MAX + 1];

int main(int argc, char * argv[]) {
  int i;

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n;
  dp[0] = 0;
  dp[1] = 1;
  dp[n] = 1;
  for(i = 2; i < n; i++)
    dp[i] = -1;

  pilloleRec(n - 1, 1);

  /*
  for(int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + (i - 1);
    count(i - 2);
  }
  */

  out << dp[n] << endl;

	in.close();
	out.close();
  return 0;
}

void pilloleRec(int intere, int mezze) {
  
  if(mezze == 0)
    if(dp[intere] != -1) {
      dp[n] += dp[intere];
      return;
    }

  if(intere > 0) {
    pilloleRec(intere - 1, mezze + 1);
    dp[n] += 1;
  }
  if(mezze > 0) {
    pilloleRec(intere, mezze - 1);
    dp[n] += 1;
  }
}
