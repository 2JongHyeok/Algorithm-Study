#include <iostream>
#include <vector>

using namespace std;

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	vector<int> dp(10001,1);
	cin >> n;

	for (int i = 2; i <= 10000; ++i) {
		dp[i] += dp[i - 2];
	}

	for (int i = 3; i <= 10000; ++i) {
		dp[i] += dp[i - 3];
	}

	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		cout << dp[num] << "\n";
	}
}