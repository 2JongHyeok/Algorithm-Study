#include <iostream>
#include <vector>

using namespace std;

#define INF 0x7FFFFFFF

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, M;
	vector<vector<long long>> costs;
	cin >> N >> M;
	costs.resize(N);
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j)
				costs[i].emplace_back(0);
			else
				costs[i].emplace_back(INF);
		}
	}

	for (int i = 0; i < M; ++i) {
		int start, end, cost;
		cin >> start >> end >> cost;
		if (costs[start - 1][end - 1] > cost) costs[start - 1][end - 1] = cost;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (costs[j][i] + costs[i][k] < costs[j][k]) {
					costs[j][k] = costs[j][i] + costs[i][k];
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (costs[i][j] == INF) cout << "0 ";
			else cout << costs[i][j] << " ";
		}
		cout << "\n";
	}
}