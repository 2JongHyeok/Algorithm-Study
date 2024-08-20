#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);


	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, 0));

	int dest_x;
	int dest_y;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 2) {
				dest_x = j;
				dest_y = i;
				v[i][j] = 0;
			}
		}
	}

	queue<pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(dest_y, dest_x),0));

	int x, y, count;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	while (!q.empty()) {
		y = q.front().first.first;
		x = q.front().first.second;
		count = q.front().second;
		q.pop();
		if (v[y][x] > 1) continue;
		for (int i = 0; i < 4; ++i) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) continue;
			if (v[new_y][new_x] > 1)continue;
			if (v[new_y][new_x] == 0)continue;
			q.push(make_pair(make_pair(new_y, new_x), count+1));
		}
		v[y][x] = count;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == 1)
				v[i][j] = -1;
		}
	}
	for (int i = 0; i < 4; ++i) {
		int new_x = dest_x + dx[i];
		int new_y = dest_y + dy[i];
		if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) continue;
		if (v[new_y][new_x] == 0)continue;
		if (v[new_y][new_x] == -1)continue;
		v[new_y][new_x] = 1;
	}
	

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}	