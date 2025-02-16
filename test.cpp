#include <iostream>
#include	<vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	vector<int> v;
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	vector<int> forwardDp;
	vector<int> backwardDp;
	vector<int> forwardDpCount;
	vector<int> backwardDpCount;
	forwardDp.emplace_back(v[0]);
	backwardDp.emplace_back(v[n-1]);
	forwardDpCount.emplace_back(1);
	backwardDpCount.emplace_back(1);

	for (int i = 1; i < n; ++i) {
		if (v[i] > forwardDp[forwardDp.size() - 1]) {
			forwardDp.emplace_back(v[i]);
			forwardDpCount.emplace_back(forwardDp.size());
			continue;
		}
		for (int j = 0; j < forwardDp.size(); ++j) {
			if (v[i] <= forwardDp[j]) {
				forwardDp[j] = v[i];
				break;
			}
		}
		forwardDpCount.emplace_back(forwardDp.size());
	}
	for (int i = n-2; i >=0; --i) {
		if (v[i] > backwardDp[backwardDp.size() - 1]) {
			backwardDp.emplace_back(v[i]);
			backwardDpCount.emplace_back(backwardDp.size());
			continue;
		}
		for (int j = 0; j < backwardDp.size(); ++j) {
			if (v[i] <=backwardDp[j]) {
				backwardDp[j] = v[i];
				break;
			}
		}
		backwardDpCount.emplace_back(backwardDp.size());

	}
	int max = 0;
	for (int i = 0; i < n; ++i) {
		int temp = forwardDpCount[i] + backwardDpCount[n-i-1];
		if (temp > max)
			max = temp;
	}
	cout << max-1;
}