#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int maxDp[2][3];
int minDp[2][3];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N;
	cin >> N;
	int nums[3];
	for (int i = 0; i < 3; ++i) {
		cin >> nums[i];
	}
	maxDp[0][0] = nums[0];
	maxDp[0][1] = nums[1];
	maxDp[0][2] = nums[2];
	minDp[0][0] = nums[0];
	minDp[0][1] = nums[1];
	minDp[0][2] = nums[2];
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> nums[j];
		}
		maxDp[1][0] = max(maxDp[0][1], maxDp[0][0]) + nums[0];
		maxDp[1][1] = max(max(maxDp[0][1], maxDp[0][0]),maxDp[0][2]) + nums[1];
		maxDp[1][2] = max(maxDp[0][1], maxDp[0][2]) + nums[2];
		minDp[1][0] = min(minDp[0][1], minDp[0][0]) + nums[0];
		minDp[1][1] = min(min(minDp[0][1], minDp[0][0]), minDp[0][2]) + nums[1];
		minDp[1][2] = min(minDp[0][1], minDp[0][2]) + nums[2];
		for (int i = 0; i < 3; ++i) {
			maxDp[0][i] = maxDp[1][i];
			minDp[0][i] = minDp[1][i];
		}
	}
	cout << max(max(maxDp[0][1], maxDp[0][0]), maxDp[0][2])<<" ";
	cout << min(min(minDp[0][1], minDp[0][0]), minDp[0][2]);
}