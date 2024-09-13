#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<pair<int, int>>> v(801, vector<pair<int, int>>());
long long val[3][801];
long long INF = 1e10;

void Dijkstra(int n, int count) {
	priority_queue < pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push(make_pair(0, n));
	val[count][n] = 0;
	while (!pq.empty()) {
		long long dis = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		for (pair p : v[now]) {
			if (val[count][p.first] < p.second + dis) continue;
			val[count][p.first] = p.second + dis;
			pq.push(make_pair(p.second + dis, p.first));
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, E;
	cin >> N >> E;
	

	for (int i = 0; i < E; ++i) {
		int start, end, value;
		cin >> start >> end >> value;
		v[start].emplace_back(make_pair(end, value));
		v[end].emplace_back(make_pair(start, value));
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 801; ++j) {
			val[i][j] = INF;
		}
	}

	int first, second;
	cin >> first >> second;

	Dijkstra(1, 0);
	Dijkstra(first, 1);
	Dijkstra(second, 2);

	long long count1 = INF;
	long long count2 = INF;
	if (val[0][first] != 1e10 && val[1][second] != 1e10 && val[2][N] != 1e10) {
		count1 = val[0][first] + val[1][second] + val[2][N];
	}
	if (val[0][second] != 1e10 && val[2][first] != 1e10 && val[1][N] != 1e10) {
		count2 = val[0][second] + val[2][first] + val[1][N];
	}
	long long answer = min(count1, count2);
	if (answer == INF)
		cout << -1;
	else
		cout << answer;
}	
 