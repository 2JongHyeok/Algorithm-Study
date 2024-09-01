#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	int num;
	int line;
	vector<vector<int>> dp(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {
		line = 0;
		for (int j = 0; j < N; ++j) {
			cin >> num;
			line += num;
			if (i > 0) {
				dp[i][j] = dp[i - 1][j] + line;
			}
			else
				dp[i][j] = line;
		}
	}
	int x1, x2, y1, y2;
	for (int i = 0; i < M; ++i) {
		cin >> y1 >> x1 >> y2 >> x2;
		x1--; x2--; y1--; y2--;
		int answer = dp[y2][x2];
		if (x1 - 1 >= 0) {
			answer -= dp[y2][x1 - 1];
		}
		if (y1 - 1 >= 0) {
			answer -= dp[y1 - 1][x2];
		}
		if(x1-1>=0 && y1-1>=0)
			 answer+= dp[y1 - 1][x1 - 1];
		cout << answer << "\n";
	}

}