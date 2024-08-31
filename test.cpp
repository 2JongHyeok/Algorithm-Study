#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int T,N;
	cin >> T;
	for (int test = 0; test < T; ++test) {
		cin >> N;
		vector<vector<int>> stickers(2, vector<int>(N, 0));
		vector<vector<int>> dp(2, vector<int>(N, 0));
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> stickers[i][j];
			}
		}
		dp[0][0] = stickers[0][0];
		dp[1][0] = stickers[1][0];
		if (N == 1) {
			cout << max(dp[0][0], dp[1][0]) << "\n";
			continue;
		}
		dp[0][1] = stickers[0][1] + stickers[1][0];
		dp[1][1] = stickers[1][1] + stickers[0][0];
		for (int i = 2; i < N; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (j == 0) {
					dp[j][i] = max(dp[1][i - 2], max(dp[1][i - 1], dp[0][i - 2])) + stickers[j][i];
				}
				else if (j == 1) {
					dp[j][i] = max(dp[0][i - 2], max(dp[0][i - 1], dp[1][i - 2])) + stickers[j][i];
				}
			}
		}
		
		cout << max(max(dp[0][N - 1], dp[1][N - 1]), max(dp[0][N - 2], dp[1][N - 2]))<<"\n";
	}
}