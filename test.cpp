#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	vector<int> board(101, -1);

	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> ladder;
	vector<pair<int, int>> snake;
	int start, end;
	for (int i = 0; i < N; ++i) {
		cin >> start >> end;
		ladder.emplace_back(make_pair(start, end));
	}
	for (int i = 0; i < M; ++i) {
		cin >> start >> end;
		snake.emplace_back(make_pair(start, end));
	}
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	int answer = 0;
	while (!q.empty()) {
		if (answer != 0)break;
		int now = q.front().first;
		int count = q.front().second;
		q.pop();
		if (board[now] != -1)continue;
		board[now] = count;
		for (int i = 1; i <= 6; ++i) {
			int new_pos = now + i;
			if (new_pos > 100) {
				answer = count + 1;
				break;
			}
			bool noLadder = false;
			bool noSnake = false;
			while (!noLadder || !noSnake) {
				noLadder = true;
				noSnake = true;
				for (int j = 0; j < N; ++j) {
					if (ladder[j].first == new_pos) {
						board[new_pos] = count;
						new_pos = ladder[j].second;
						noLadder = false;
					}
				}
				for (int j = 0; j < M; ++j) {
					if (snake[j].first == new_pos) {
						board[new_pos] = count;
						new_pos = snake[j].second;
						noSnake = false;
					}
				}
			}
			q.push(make_pair(new_pos, count + 1));
		}
	}
	cout << answer;
}	