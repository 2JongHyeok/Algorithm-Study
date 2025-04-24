#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
constexpr int INF = numeric_limits<int>::max();

int N, M, X;

void dijkstra(const int start, const vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
	dist.assign(N + 1, INF);
	dist[start ] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		auto [curr_dist, u] = pq.top(); pq.pop();
		if (curr_dist > dist[u]) continue;

		for (auto [v, weight] : graph[u]) {
			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push({ dist[v],v });
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M >> X;

	vector<vector<pair<int, int>>> map(N+1);
	vector<vector<pair<int, int>>> rev_map(N+1);
	
	for (int i = 0; i < M; ++i) {	// 시간 초기화
		int u, v, w;
		cin >> u >> v >> w;
		map[u].emplace_back(v, w);
		rev_map[v].emplace_back(u, w);
	}

	vector<int> toX(N + 1), fromX(N + 1);
	dijkstra(X, map, fromX);
	dijkstra(X, rev_map, toX);

	int max_time = 0;
	for (int i = 1; i <= N; ++i) {
		int round = toX[i] + fromX[i];
		max_time = max(max_time, round);
	}

	cout << max_time;
	return 0;
}