#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	vector<vector<pair<int, int>>> buses(M+1, vector<pair<int,int>>());
	vector<int>costs(N + 1, INFINITY);

	std::priority_queue<pair<int,long long>, std::vector<pair<int, long long>>, std::greater<pair<int, long long>>> pq;

	int start, end;
	long long cost;

	for (int i = 0; i < M; ++i) {
		cin >> start >> end >> cost;
		buses[start].emplace_back(make_pair(end, cost));
	}

	cin >> start >> end;
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int current = pq.top().first;
		int value = pq.top().second;
		pq.pop();
		if (costs[current] < value) continue;	
		for (auto b : buses[current]) {
			int next = b.first;
			int nextValue = b.second + value;
			if (nextValue < costs[next]) {
				costs[next] = nextValue;
				pq.push(make_pair(next, nextValue));
			}
		}
	}

	cout << costs[end];
}