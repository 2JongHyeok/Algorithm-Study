#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	char** arr = new char*[N];
	unordered_map<int, vector<int>> graph;
	for (int i = 0; i < N; ++i) {
		arr[i] = new char[M];
	}

	int my;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 'O') {
				if (i != 0) {
					if (arr[i - 1][j] != 'X') {
						graph[i * M + j].emplace_back((i - 1) * M + j);
						graph[(i - 1) * M + j].emplace_back(i * M + j);
					}
				}
				if (j != 0) {
					if (arr[i][j-1] != 'X') {
						graph[i * M + j].emplace_back(i * M + j-1);
						graph[i * M + j-1].emplace_back(i * M + j);
					}
				}
			}
			else if (arr[i][j] == 'I') {
				my = i * M + j;
				if (i != 0) {
					if (arr[i - 1][j] != 'X') {
						graph[i * M + j].emplace_back((i - 1) * M + j);
						graph[(i - 1) * M + j].emplace_back(i * M + j);
					}
				}
				if (j != 0) {
					if (arr[i][j - 1] != 'X') {
						graph[i * M + j].emplace_back(i * M + j - 1);
						graph[i * M + j - 1].emplace_back(i * M + j);
					}
				}
			}
			else if (arr[i][j] == 'P') {
				if (i != 0) {
					if (arr[i - 1][j] != 'X') {
						graph[i * M + j].emplace_back((i - 1) * M + j);
						graph[(i - 1) * M + j].emplace_back(i * M + j);
					}
				}
				if (j != 0) {
					if (arr[i][j - 1] != 'X') {
						graph[i * M + j].emplace_back(i * M + j - 1);
						graph[i * M + j - 1].emplace_back(i * M + j);
					}
				}
			}
		}
	}
	
	queue<int> canGo;
	set<int> went;
	canGo.push(my);

	int now;
	int count = 0;

	while (!canGo.empty()) {
		if (went.find(canGo.front()) != went.end()) {
			canGo.pop();
			continue;
		}
		now = canGo.front();
		canGo.pop();
		went.insert(now);
		for (int path : graph[now]) {
			canGo.push(path);
		}
		if (arr[now / M][now % M] == 'P')
			count++;
	}
	if (count > 0)
		cout << count;
	else
		cout << "TT";
}