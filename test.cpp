#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int N, M;

bool visited[1000][1000][2];	// 방문여부 + 벽을 부쉈는지 안부쉈는지

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	cin >> N >> M;
	vector<vector<char>> map(N, vector<char>(M, 0));


	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < M; ++j) {
			map[i][j] = s[j];
		}
	}

	if (N == 1 && M == 1) {
		cout << 1;
		return 0;
	}
	queue <tuple<int, int, int, bool>> q;

	q.push({ 1,0, 0, false });
	
	int X[4]{ 1,0,0,-1 };
	int Y[4]{ 0,1,-1,0 };
	bool found = false;
	while (!q.empty()) {
		auto [time, x, y, broken] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int newX = x + X[i], newY = y+Y[i];
			if (newX < 0 || newX >= M || newY < 0 || newY >= N) continue;
			if (newX == M - 1 && newY == N - 1) {
				found = true;
				cout << time + 1;
				break;
			}
			if (broken) {
				if (map[newY][newX] == '1') continue;
				if (visited[newY][newX][0]) continue;
				visited[newY][newX][0] = true;
				visited[newY][newX][1] = true;
				q.push({ time + 1, newX, newY, broken });
			}
			else {
				if (visited[newY][newX][0] && !visited[newY][newX][1]) continue;
				if (map[newY][newX] == '1') {
					q.push({ time + 1, newX, newY, true });
					
				}
				else {
					q.push({ time + 1, newX, newY, false });
				}
				visited[newY][newX][0] = true;
				visited[newY][newX][1] = false;
			}
		}
		if (found)
			break;
	}
	if (!found) {
		cout << -1;
	}

	return 0;
}