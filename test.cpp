#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N;
	cin >> N;
	int houses[1000][3]{0};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> houses[i][j];
		}
	}
	int dp[1000][3]{0};
	dp[0][0] = houses[0][0];
	dp[0][1] = houses[0][1];
	dp[0][2] = houses[0][2];
	for (int i = 1; i < N; ++i) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + houses[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + houses[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + houses[i][2];
	}
	cout << min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
}