#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;
constexpr int INF = numeric_limits<int>::max();

int N, M, W;

bool bellman_ford(const vector<tuple<int,int,int>>& edges)
{
	vector<int> dist(N + 1, INF);

	dist[0] = 0;
	
	for (int i = 0; i < N; ++i) {
		for (auto [u, v, w] : edges) {
			if (dist[u] != INF && dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
			}
		}
	}

	for (auto [u, v, w] : edges) {
		if (dist[u] != INF && dist[v] > dist[u] + w) {
			return true;
		}
	}
	return false;

}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int TC;
	cin >> TC;

	for (int tc = 0; tc < TC; ++tc) {
		cin >> N >> M >> W;
		vector<tuple<int, int, int>> edges;
		for (int i = 0; i < M; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			edges.emplace_back( u,v,w );
			edges.emplace_back( v,u,w );
		}
		for (int i = 0; i < W; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			edges.emplace_back(u, v, -w);
		}
		for (int i = 1; i <= N; ++i) {
			edges.emplace_back(0, i, 0);
		}
		if (bellman_ford(edges)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}