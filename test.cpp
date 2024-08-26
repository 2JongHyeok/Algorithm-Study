#include <iostream>

using namespace std;
int N, M;
int paper[500][500];
int visited[500][500];
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};
int Max = 0;
void DFS(int x, int y, int count, int num) {
	for (int i = 0; i < 4; ++i) {
		int new_x = x + X[i];
		int new_y = y + Y[i];
		if (new_x <0 || new_x > M - 1 || new_y < 0 || new_y > N - 1) continue;
		if (visited[new_y][new_x] == 1)continue;
		if (count == 3) {
			if (Max < num + paper[new_y][new_x])
				Max = num + paper[new_y][new_x];
			continue;
		}
		visited[new_y][new_x] = 1;
		DFS(new_x, new_y, count + 1, num + paper[new_y][new_x]);
		visited[new_y][new_x] = 0;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> paper[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			visited[i][j] = 1;
			DFS(j, i, 1, paper[i][j]);
			visited[i][j] = 0;
			int sum, dx, dy;
			for (int k = 0; k < 4; k++)
			{
				sum = paper[i][j];
				for (int dir = 0; dir < 4; dir++)
				{
					if (dir == k)
						continue;
					dx = j + X[dir];
					dy = i + Y[dir];
					if (dx >= 0 && dx < M && dy >= 0 && dy < N)
						sum += paper[dy][dx];
					else {
						break;
					}
				}
				if (Max < sum)
					Max = sum;
			}
		}
	}
	cout << Max;
}