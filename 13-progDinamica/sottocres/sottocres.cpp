#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int sottoseq(int n, vector<int> nums);
int sumPrec(int x, vector<int> nums, int maxSum[]);

int main(int argc, char * argv[]) {
	int n;
  int i;
  vector<int> nums; 

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n;
  nums.resize(n);
  for(i = 0; i < n; i++)
    in >> nums[i];

  out << sottoseq(n, nums) << endl;

	in.close();
	out.close();
  return 0;
}

int sottoseq(int n, vector<int> nums) {
  int maxSum[n];
  int i;

  for(i = 0; i < n; i++) {
    maxSum[i] = sumPrec(i, nums, maxSum) + nums[i];
    cout << maxSum[i] << " ";
  }

  return *max_element(maxSum, maxSum + n);
}

int sumPrec(int x, vector<int> nums, int maxSum[]) {
  int i;
  int max = 0;

  for(i = x - 1; i >= 0; i--) {
    if(nums[i] <= nums[x] && max < maxSum[i])
      max = maxSum[i];
  }
  return max;
}
