#include <iostream>
#include <vector>

#define MAX  0x7FFFFFFF

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	vector<vector<long long>> map;
	vector<int> items;
	int n, m, r;
	cin >> n >> m >> r;

	map.resize(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			map[i].emplace_back(MAX);


	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		items.emplace_back(tmp);
	}

	for (int i = 0; i < r; ++i) {
		int start, end, val;
		cin >> start >> end >> val;
		map[start-1][end-1] = val;
		map[end-1][start-1] = val;
	}

	for (int i = 0; i < n; ++i) map[i][i] = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (map[j][i] + map[i][k] < map[j][k]) {
					map[j][k] = map[j][i] + map[i][k];
				}
			}
		}
	}

	int answer = 0;

	for (int i = 0; i < n; ++i) {
		int temp = 0;
		for (int j = 0; j < n; ++j) {
			if (map[i][j] <= m)
				temp += items[j];
		}
		if (temp > answer)
			answer = temp;
	}

	cout << answer;
}