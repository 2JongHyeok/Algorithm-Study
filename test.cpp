#include <iostream>
#include <vector>

using namespace std;
vector<int> parent(51,0);
vector<vector<int>> party(50, vector<int>());

int Find(int num) {
	if (num != parent[num])
		parent[num] = Find(parent[num]);
	return parent[num];
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a < b)
		parent[b] = a;
	else {
		parent[a] = b;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	for (int i = 0; i <= N; ++i) {
		parent[i] = i;
	}
	int knowTruth;
	cin >> knowTruth;
	for (int i = 0; i < knowTruth; ++i) {
		int num;
		cin >> num;
		parent[num] = 0;
	}

	for (int i = 0; i < M; ++i) {
		int num;
		cin >> num;
		for (int j = 0; j < num; ++j) {
			int people;
			cin >> people;
			party[i].emplace_back(people);
			if (j != 0) {
				Union(party[i][j], party[i][j-1]);
			}
		}
	}
	int count = 0;
	for (int i = 0; i < M; ++i) {
		if (Find(party[i][0]) != 0)count++;
	}
	cout << count;
}	
 