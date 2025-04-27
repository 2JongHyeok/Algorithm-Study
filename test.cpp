#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int N, M;
vector<vector<int>> map;
bool visited[100][100];
struct pos
{
	int x, y;
};
struct info
{
	pos p;
	int count;
};
queue<info> cheese;

int BFS()
{
	// step 1 : 바깥공기 찾기
	queue<pos> q;
	q.push({ 0,0 });
	visited[0][0] = true;
	int X[4]{ 1,-1,0,0 };
	int Y[4]{ 0,0,1,-1 };
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int newX = x + X[i];
			int newY = y + Y[i];
			if (newX < 0 || newX >= M || newY < 0 || newY >= N) continue;
			if (map[newY][newX] == 1) continue;
			if (visited[newY][newX]) continue;
			visited[newY][newX] = true;
			q.push({ newX, newY });
		}
	}

	// step 2 : 치즈 녹이기
	int finishTime = 0;
	while (!cheese.empty()) {
		auto [pos, time] = cheese.front(); cheese.pop();
		int count = 0;
		if (finishTime != time) {
			finishTime++;
			while (!q.empty()) {
				auto [x, y] = q.front(); q.pop();
				map[y][x] = 0;
				visited[y][x] = true;
				for (int i = 0; i < 4; ++i) {
					int newX = x + X[i];
					int newY = y + Y[i];
					if (newX < 0 || newX >= M || newY < 0 || newY >= N) continue;
					if (map[newY][newX] == 1) continue;
					if (visited[newY][newX]) continue;
					visited[newY][newX] = true;
					q.push({ newX, newY });
				}
			}
		}
		for (int i = 0; i < 4; ++i) {
			int newX = pos.x + X[i];
			int newY = pos.y + Y[i];
			if (newX < 0 || newX >= M || newY < 0 || newY >= N) continue;
			if (visited[newY][newX])
				count++;
		}
		if (count >= 2) {
			q.push(pos);
		}
		else {
			cheese.push({ pos,time + 1 });
		}
	}
	return finishTime+1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	cin >> N >> M;
	map.resize(N, vector<int>(M));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				cheese.push({ j,i,0 });
		}
	}

	int time = BFS();
	cout << time;
}