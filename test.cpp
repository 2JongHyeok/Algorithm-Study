#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int M, N, H;
	cin >> M >> N >> H;
	vector<vector<vector<int>>> v(H, vector<vector<int>>(N, vector<int>(M,0)));
	queue<pair<pair<int, int>, pair<int, int>>> q;
	for (int h = 0; h < H; ++h) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				int num;
				cin >> num;
				v[h][i][j] = num;
				if (num == 1) {
					q.push(make_pair(make_pair(i, j), make_pair(h, 0)));
					v[h][i][j] = 0;
				}
			}
		}
	}

	int X[4]{ 0,0,1,-1 };
	int Y[4]{ 1,-1,0,0 };
	int Z[2]{ 1,-1};
	
	int max = -1;

	while (!q.empty()) {
		pair<pair<int, int>, pair<int, int>> p = q.front();
		q.pop();
		if (v[p.second.first][p.first.first][p.first.second] == 0) {
			v[p.second.first][p.first.first][p.first.second] = 1;
			for (int i = 0; i < 4; ++i) {
				int new_x = p.first.second + X[i];
				int new_y = p.first.first + Y[i];
				int z = p.second.first;

				if (new_x < 0 || new_x > M - 1 || new_y < 0 || new_y > N - 1)continue;
				if (v[z][new_y][new_x] == 0) {
					q.push(make_pair(make_pair(new_y, new_x), make_pair(z, p.second.second + 1)));
				}
			}
			for (int i = 0; i < 2; ++i) {
				int new_z = p.second.first + Z[i];
				int x = p.first.second;
				int y = p.first.first;
				if (new_z < 0 || new_z > H - 1)continue;
				if (v[new_z][y][x] == 0) {
					q.push(make_pair(make_pair(y, x), make_pair(new_z, p.second.second + 1)));
				}
			}
			max = p.second.second;
		}
	}

	for (int h = 0; h < H; ++h) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (v[h][i][j] == 0) {
					max = -1;
				}
			}
		}
	}

	cout << max;
}	