#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<char>> v(20, vector<char>(20, 'a'));
map<char, bool> m;
int max_count = 0;
int X[4]{ 0,0,1,-1 };
int Y[4]{ 1,-1,0,0};
int R, C;

void DFS(pair<int,int> pos, int count) {
	if (max_count < count) {
		max_count = count;
	}

	for (int i = 0; i < 4; ++i) {
		int new_x = pos.second + X[i];
		int new_y = pos.first + Y[i];
		if (new_y < 0 || new_y > R - 1 || new_x < 0 || new_x > C - 1) continue;
		if (m[v[new_y][new_x]]) continue;
		m[v[new_y][new_x]] = true;
		DFS(make_pair(new_y, new_x), count + 1);
		m[v[new_y][new_x]] = false;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);



	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> v[i][j];
		}
	}
	m[v[0][0]] = true;
	DFS(make_pair(0, 0), 1);
	cout << max_count;
}