#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);


	int N;
	cin >> N;
	vector<vector<int>> Map(N, vector<int>(N,0));
	vector<vector<bool>> visited(N, vector<bool>(N,false));
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < N; ++j) {
			Map[i][j] = int(s[j] - '0');
			if (Map[i][j] == 0) {
				visited[i][j] = true;
			}
		}
	}

	queue<pair<int, int>> q;

	pair<int, int> pos;

	vector<int> complex(1,0);
	int index = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (visited[i][j])
				continue;
			q.push(make_pair(i, j));
			while (!q.empty()) {
				pos = q.front();
				q.pop();
				if (visited[pos.first][pos.second])
					continue;
				visited[pos.first][pos.second] = true;
				if (index == complex.size()) {
					complex.emplace_back(0);
				}
				complex[index]++;
				if (!visited[max(0, pos.first - 1)][pos.second])
					q.push(make_pair(max(0, pos.first - 1), pos.second));
				if (!visited[min(N-1, pos.first+1)][pos.second])
					q.push(make_pair(min(N-1, pos.first + 1), pos.second));
				if (!visited[pos.first][max(0,pos.second-1)])
					q.push(make_pair(pos.first , max(0, pos.second - 1)));
				if (!visited[pos.first][min(N-1, pos.second + 1)])
					q.push(make_pair(pos.first, min(N-1, pos.second + 1)));
			}
			index++;
		}
	}
	cout << complex.size()<<"\n";
	sort(complex.begin(), complex.end());
	for (int num : complex) {
		cout << num << "\n";
	}


}
