#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int arr[1000001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	cin >> T;
	int dp[12];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 11; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	int num;
	for (int i = 0; i < T; ++i) {
		cin >> num;
		cout << dp[num] << "\n";
	}
}