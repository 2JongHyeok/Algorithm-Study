#include <iostream>
#include <vector>
#include <set>

using namespace std;
vector<vector<int>> visited(100, vector<int>(100, 0));
vector<set<int>> can_go(100);


void search(int start, int end) {
	visited[start][end] = 1;
	for (int num : can_go[end]) {
		if (visited[start][num] == 1) continue;
		visited[start][num] = 1;
		search(start, num);
	}
}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;
	
	int num;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> num;
			if (num == 1)
				can_go[i].insert(j);
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int num : can_go[i]) {
			search(i, num);
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}

}