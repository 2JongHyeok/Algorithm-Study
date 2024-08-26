#include <iostream>
#include <vector>

using namespace std;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;
	int num;
	vector<int> v(N,0);
	vector<int> dp;
	dp.emplace_back(0);
	bool add = false;
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		if (v[i] > dp[dp.size() - 1]) {
			dp.emplace_back(v[i]);
			continue;
		}

		for (int j = 1; j <dp.size(); ++j) {
			if (v[i] <= dp[j]) {
				dp[j] = v[i];
				break;
			}
		}
	}
	cout << dp.size()-1;
}