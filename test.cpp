#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 1e9;

vector<vector<pair<int, int>>> v(20'001, vector<pair<int,int>>()) ;
int val[20'001];

void dijkstra(int start) {
	val[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = pq.top().first;
		pq.pop();
		if (val[current] < distance)continue;
		for (int i = 0; i < v[current].size(); ++i) {
			int next = v[current][i].second;
			int nextDis = distance + v[current][i].first;
			if (nextDis < val[next]) {
				val[next] = nextDis;
				pq.push(make_pair(nextDis, next));
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int V, E;
	cin >> V >>E;
	for (int i = 1; i <= V; ++i) {
		val[i] = INF;
	}

	int K;
	cin >> K;

	for (int i = 0; i < E; ++i) {
		int start, end, weight;
		cin >> start >> end >> weight;
		v[start].emplace_back(weight, end);
	}
	dijkstra(K);
	for (int i = 1; i <= V; ++i) {
		if (val[i] == 1e9)
			cout << "INF\n";
		else
			cout << val[i] << "\n";
	}
}	
 