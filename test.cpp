#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N;
	cin >> N;
	int num;
	vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, 0)));
	vector<vector<int>> house(N, vector<int>(N,0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> house[i][j];
		}
	}
	dp[0][0][0] = 1;
	dp[0][1][0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (j > 1) {
				if (house[i][j] == 0) {
					dp[i][j][0] = dp[i][j - 1][0] + dp[i][j-1][1];
				}
				if (i > 0) {
					if (house[i][j] == 0 && house[i - 1][j] == 0 && house[i][j - 1] == 0) {
						dp[i][j][1] += (dp[i - 1][j - 1][0]+dp[i-1][j-1][1] + dp[i-1][j-1][2]);
					}
					if (house[i][j] == 0 && i>1) {
						dp[i][j][2] += (dp[i - 1][j][1] + dp[i-1][j][2]);
					}
				}
			}
		}
	}
	cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1]+ dp[N - 1][N - 1][2];
}	
 