#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N;
	cin >> N;

	vector<vector<char>> painting(N, vector<char>(N,'0'));
	vector<vector<bool>> RGvisited(N, vector<bool>(N, false));
	vector<vector<bool>> visited(N, vector<bool>(N, false));

	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < N; ++j) {
			painting[i][j] = s[j];
		}
	}

	queue<pair<int, int>> RGq;
	queue<pair<int, int>> q;

	int RG_sec_num = 0;
	int sec_num = 0;

	int X[4] = { 0,0,1,-1 };
	int Y[4] = { 1,-1,0,0 };
	char now_color = 'R';
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j]) {
				q.push(make_pair(i, j));
				sec_num++;
				now_color = painting[i][j];
			}
			if (!RGvisited[i][j]) {
				RGq.push(make_pair(i, j));
				RG_sec_num++;
			}
			while (!RGq.empty()) {
				pair<int, int> p = RGq.front();
				RGq.pop();
				if (RGvisited[p.first][p.second]) continue;
				RGvisited[p.first][p.second] = true;
				for (int i = 0; i < 4; ++i) {
					int new_x = p.second + X[i];
					int new_y = p.first + Y[i];
					if (new_x < 0 || new_x > N - 1 || new_y < 0 || new_y > N - 1) continue;
					if (RGvisited[new_y][new_x]) continue;
					if (now_color == 'R' || now_color == 'G') {
						if (painting[new_y][new_x] == 'B')continue;
					}
					else if (now_color == 'B') {
						if (painting[new_y][new_x] == 'R' || painting[new_y][new_x] == 'G') continue;
					}
					RGq.push(make_pair(new_y, new_x));
				}
			}
			while (!q.empty()) {
				pair<int, int> p = q.front();
				q.pop();
				if (visited[p.first][p.second]) continue;
				visited[p.first][p.second] = true;
				for (int i = 0; i < 4; ++i) {
					int new_x = p.second + X[i];
					int new_y = p.first + Y[i];
					if (new_x < 0 || new_x > N - 1 || new_y < 0 || new_y > N - 1) continue;
					if (visited[new_y][new_x]) continue;
					if (now_color == 'R' ) {
						if (painting[new_y][new_x] == 'B' || painting[new_y][new_x] == 'G')continue;
					}
					else if (now_color == 'G') {
						if (painting[new_y][new_x] == 'R' || painting[new_y][new_x] == 'B') continue;
					}
					else if (now_color == 'B') {
						if (painting[new_y][new_x] == 'R' || painting[new_y][new_x] == 'G') continue;
					}
					q.push(make_pair(new_y, new_x));
				}
			}
		}
	}
	cout << sec_num << " " << RG_sec_num;
}	