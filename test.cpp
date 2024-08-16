#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int W[4] = { 0,0,1,-1 };
int H[4] = { 1,-1,0,0 };

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N,M;
	cin >> N >> M;

	vector<vector<int>> maze(N, vector<int>(M, 0));
	queue<pair<pair<int,int>,int>> q;

	string s;
	int num = 0;
	int p_x;
	int p_y;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		for (int j = 0; j < M; ++j) {
			if (s[j] == '#')
				num = -1;
			else if (s[j] == '.')
				num = 0;
			else if (s[j] == 'J') {
				num = 0;
				p_x = j;
				p_y = i;
			}
			else if (s[j] == 'F') {
				num = 0;
				q.push(make_pair(make_pair(i, j), -2));
			}	
			maze[i][j] = num;
		}
	}
	q.push(make_pair(make_pair(p_y, p_x), 1));
	bool escape = false;
	num = 0;

	while (!q.empty()) {
		pair<int, int> p = q.front().first;
		int who = q.front().second;
		q.pop();
		if (maze[p.first][p.second] != 0)continue;
		maze[p.first][p.second] = who;
		for (int k = 0; k < 4; ++k) {
			int x = p.second + W[k];
			int y = p.first + H[k];
			if (x < 0 || x >= M || y < 0 || y >= N) {
				if (who >= 1) {
					escape = true;
					num = who;
					break;
				}
				continue;
			}
			if (maze[y][x] != 0) continue;
			if (who == -2) {
				q.push(make_pair(make_pair(y, x), -2));
			}
			else
				q.push(make_pair(make_pair(y, x),who+1));
		}
		if (escape)
			break;
	}
	if (escape)
		cout << num;
	else
		cout << "IMPOSSIBLE";
}
