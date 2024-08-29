#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<vector<int>>nums(N,vector<int>(N,0));
	vector<vector<int>>dp(N,vector<int>(N,0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i+1; ++j) {
			cin >> nums[i][j];
		}
	}
	dp[0][0] = nums[0][0];
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i+1; ++j) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + nums[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + nums[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + nums[i][j];
			}
		}
	}

	int maxi = 0;

	for (int num : dp[N - 1]) {
		if (maxi < num)
			maxi = num;
	}
	cout << maxi;
}