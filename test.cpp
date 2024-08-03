#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	vector<int> trees(N);
	for (int i = 0; i < N; ++i) {
		cin >> trees[i];
	}
	
	sort(trees.begin(), trees.end(), greater<int>());

	long long  result = trees[0];
	long long before = 0;
	long long cut = (result + before) / 2;
	bool before_cut = false;

	while (true) {
		if (before > result)
			break;
		long long sum = 0;
		for (int i = 0; i < N; ++i) {
			if (trees[i] <= cut)
				break;
			sum += trees[i] - cut;
			if (sum>= M) {
				before = cut+1;
				cut = (result+before)/2;
				break;
			}
		}
		if (sum < M) {
			result = cut-1;
			cut = (result + before) / 2;
		}
	}
	cout << result;
}