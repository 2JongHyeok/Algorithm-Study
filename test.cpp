#include <iostream>
#include <array>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

array<vector<int>, 1001> graph;
unordered_set<int> CC;

queue<int> Component;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, M;
	cin >> N >>M;
	int start, end;
	for (int i = 0; i < M; ++i) {
		cin >> start >> end;
		graph[start].emplace_back(end);
		graph[end].emplace_back(start);
	}
	int result = 0;
	bool first = true;
	for (int i = 1; i <= N; ++i) {
		if (CC.find(i) == CC.end()) {
			result++;
			Component.push(i);
		}
		else continue;

		while (!Component.empty()) {
			int num = Component.front();
			Component.pop();
			if (CC.find(num) != CC.end()) continue;
			CC.insert(num);
			for (int a : graph[num]) {
				Component.push(a);
			}
		}
	}
	cout << result;
	
}