#include <iostream>
#include <algorithm>

using namespace std;
int dp[50'001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;
	dp[1] = 1;
	for (int i = 2; i <= N; ++i) {
		int mini = 50000;
		for(int j = 1; j * j <= i; ++j) {
			int tmp = i - j * j;
			mini = min(mini, dp[tmp]);
		}
		dp[i] = mini + 1;
	}
	cout << dp[N];
}