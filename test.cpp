#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int R, C, T;
	cin >> R >> C >> T;

	vector<vector<long long>> map;
	
	map.resize(R);

	int air_purifier=2;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			int tmp;
			cin >> tmp;
			map[i].emplace_back(tmp);
			if (tmp == -1) air_purifier = i - 1;
		}
	}

	int dirX[4] = {0,0,1,-1};
	int dirY[4] = {1,-1,0,0};

	queue<pair<pair<int, int>,long long>> diffusion;
	for (int time = 0; time < T; ++time) {
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (map[i][j] >= 5) {
					int count = 0;
					for (int dir = 0; dir < 4; ++dir) {
						int tmpX = j+dirX[dir], tmpY = i+dirY[dir];
						if (tmpX < 0 || tmpX >= C || tmpY < 0 || tmpY >= R || map[tmpY][tmpX] == -1) continue;
						diffusion.push(make_pair(make_pair(tmpY, tmpX), map[i][j] / 5));
						count++;
					}
					map[i][j] -= map[i][j] / 5 * count;
				}
			}
		}
		while (!diffusion.empty()) {
			pair<pair<int, int>, int> tmp = diffusion.front();
			diffusion.pop();
			map[tmp.first.first][tmp.first.second] += tmp.second;
		}

		for (int i = air_purifier - 1; i > 0; --i) {
			map[i][0] = map[i - 1][0];
		}
		for (int i = 0; i < C-1; ++i) {
			map[0][i] = map[0][i + 1];
		}
		for (int i = 0; i < air_purifier; ++i) {
			map[i][C-1] = map[i + 1][C-1];
		}
		for (int i = C - 1; i > 1; --i) {
			map[air_purifier][i] = map[air_purifier][i - 1];
		}
		map[air_purifier][1] = 0;
		for (int i = air_purifier + 2; i < R-1; ++i) {
			map[i][0] = map[i+1][0];
		}
		for (int i = 0; i < C - 1; ++i) {
			map[R - 1][i] = map[R - 1][i + 1];
		}
		for (int i = R - 1; i > air_purifier+1; --i) {
			map[i][C - 1] = map[i - 1][C - 1];
		}
		for (int i = C - 1; i > 1; --i) {
			map[air_purifier + 1][i] = map[air_purifier + 1][i - 1];
		}
		map[air_purifier + 1][1] = 0;
	}

	long long answer = 0;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			answer += map[i][j];
		}
	}

	cout << answer + 2;
}