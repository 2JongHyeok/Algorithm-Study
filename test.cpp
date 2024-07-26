#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

long long dp[101];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T, N;
	cin >> T;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	dp[6] = 3;
	dp[7] = 4;
	dp[8] = 5;
	dp[9] = 7;
	dp[10] = 9;
	for (int i = 11; i <= 100; ++i) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	for (int i = 0; i < T; ++i) {
		cin >> N;
		cout << dp[N] << "\n";
	}

}