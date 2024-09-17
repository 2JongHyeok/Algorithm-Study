#include <iostream>
#include <vector>

using namespace std;
vector<vector<pair<int, int>>> v(10001, vector<pair<int, int>>());
int max_distance, farthest_node;

void DFS(int start, int parent, int distance) {
	if (max_distance < distance) {
		max_distance = distance;
		farthest_node = start;
	}
	for (auto c : v[start]) {
		if (c.first == parent) continue;
		DFS(c.first, start, distance + c.second);
	}
}

void Find(int start) {
	DFS(start, -1, 0);
	int start_node = farthest_node;
	max_distance = 0;
	DFS(start_node, -1, 0);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		int start, end, weight;
		cin >> start >> end >> weight;
		v[start].emplace_back(make_pair(end, weight));
		v[end].emplace_back(make_pair(start, weight));
	}
	Find(1);
	cout << max_distance;
}