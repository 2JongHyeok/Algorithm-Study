#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int arr[1000001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int C,P;
	cin >> C >> P;
	vector<vector<int>> computers(C+1);
	int first, second;
	for (int i = 0; i < P; ++i) {
		cin >> first >> second;
		computers[first].emplace_back(second);
		computers[second].emplace_back(first);
	}
	stack<int> s;
	s.push(1);
	int now;
	set<int> result;
	while (!s.empty()) {
		now = s.top();
		s.pop();
		result.insert(now);
		for (int i = 0; i < computers[now].size(); ++i) {
			if (result.find(computers[now][i]) != result.end())
				continue;
			s.push(computers[now][i]);
			result.insert(computers[now][i]);
		}
	}
	cout << result.size()-1;
}