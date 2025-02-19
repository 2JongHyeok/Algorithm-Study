#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;
vector<pair<int, int>> space;

int N, M;

int BFS(vector<vector<int>> tmpMap, queue<pair<int, int>> q,int firstWall, int secondWall, int thirdWall) {
	int count = 0;
	int disX[4] = { -1,0,0,1 };
	int disY[4] = { 0,1,-1,0 };
	tmpMap[space[firstWall].first][space[firstWall].second] = 1;
	tmpMap[space[secondWall].first][space[secondWall].second] = 1;
	tmpMap[space[thirdWall].first][space[thirdWall].second] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int temp_x= x + disX[i];
			int temp_y = y + disY[i];
			if (temp_x <0 || temp_x >=M || temp_y <0 || temp_y >=N) continue;
			if (tmpMap[temp_y][temp_x] != 0) continue;
			tmpMap[temp_y][temp_x] = 2;
			q.push(make_pair(temp_y, temp_x));
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (tmpMap[i][j] == 0) count++;
		}
	}
	return count;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	queue<pair<int, int>> q;
	cin >> N >> M;
	map.resize(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int tmp;
			cin >> tmp;
			map[i].emplace_back(tmp);
			if (tmp == 0) space.emplace_back(make_pair(i, j));
			if (tmp == 2)q.push(make_pair(i, j));
		}
	}

	int max = 0;

	for (int i = 0; i < space.size(); ++i) {
		for (int j = i+1; j < space.size(); ++j) {
			for (int k = j+1; k < space.size(); ++k) {
				int tmp = BFS(map,q,i,j,k);
				if (tmp > max)
					max = tmp;
			}
		}
	}

	cout << max;

}