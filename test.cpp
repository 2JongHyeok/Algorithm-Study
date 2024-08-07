#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	map<int,vector<int>> v;
	int friend1, friend2;
	for (int i = 0; i < M; ++i) {
		cin >> friend1 >> friend2;
		v[friend1].emplace_back(friend2);
		v[friend2].emplace_back(friend1);
	}

	vector<int> kevin(N);
	vector<set<int>> went(N, set<int>());
	queue<int> q;
	vector<int> person_count(N+1);
	int now = 0;
	int k = 0;
	for (int i = 0; i < N; ++i) {
		q.push(i+1);
		k = 0;
		person_count[0] = 1;
		while (!q.empty()) {
			if (person_count[k] == 0) {
				k++;
			}
			now = q.front();
			q.pop();
			person_count[k]--;
			if (went[i].find(now) != went[i].end()) {
				continue;
			}
			went[i].insert(now);
			for (int person : v[now]) {
				person_count[k+1] += 1;
				q.push(person);
			}
			kevin[i] += k;
		}
	}
	int min = 5001;
	int answer = 0;
	for (int i = 0; i < N; ++i ) {
		if (min > kevin[i]) {
			min = kevin[i];
			answer = i+1;
		}
	}
	cout << answer;
}
