#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(N, vector<int>(M, 0));
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < M; ++j) {
			v[i][j] = int(s[j] - '0');
		}
	}

	queue<pair<int, int>> q;
	vector<int>count(N*M, 0);
	int answer = 0;
	count[0]++;
	q.push(make_pair(0, 0));
	pair<int,int> now;
	while (true) {
		if (count[answer] == 0) {
			answer++;
		}
		now = q.front();
		q.pop();
		count[answer]--;
		if (now.first == N - 1 and now.second == M - 1) {
			cout << answer+1;
			break;
		}
		if (!visited[max(now.first - 1, 0)][now.second] and v[max(now.first - 1, 0)][now.second] == 1) {
			visited[max(now.first - 1, 0)][now.second] = true;
			q.push(make_pair(max(now.first - 1, 0), now.second));
			count[answer + 1]++;
		}
		if (!visited[min(now.first + 1, N-1)][now.second] and v[min(now.first + 1, N - 1)][now.second] == 1){
			visited[min(now.first + 1, N-1)][now.second] = true;
			q.push(make_pair(min(now.first + 1, N-1), now.second));
			count[answer + 1]++;
		}
		if (!visited[now.first] [max(now.second - 1, 0)] and v[now.first][max(now.second - 1, 0)] == 1){
			visited[now.first][max(now.second - 1, 0)] = true;
			q.push(make_pair(now.first, max(now.second - 1, 0)));
			count[answer + 1]++;
		}
		if (!visited[now.first][min(now.second + 1, M-1)] and v[now.first][min(now.second + 1, M - 1)] == 1) {
			visited[now.first][min(now.second + 1, M-1)] = true;
			q.push(make_pair(now.first, min(now.second + 1, M-1)));
			count[answer + 1]++;
		}
	}
}
