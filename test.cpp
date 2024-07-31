#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;
unordered_map<int, set<int>> umap ;
unordered_map<int, int> dfs;
unordered_map<int, int> bfs;

void do_dfs(int v) {
	if (dfs[v] == 1)
		return;
	dfs[v] = 1;
	cout << v << " ";
	for (auto n : umap[v]) {
		do_dfs(n);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	queue<int> q;
	int N, V, M;
	cin >> N >> M >> V;
	int start, end;
	for (int i = 0; i < M; ++i) {
		cin >> start >> end;
		umap[start].insert(end);
		umap[end].insert(start);
	}

	do_dfs(V);
	cout << "\n";

	q.push(V);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (bfs[node] == 1)
			continue;
		cout << node << " ";
		bfs[node] = 1;
		for (int n : umap[node]) {
			q.push(n);
		}
	}
	cout << "\n";

}