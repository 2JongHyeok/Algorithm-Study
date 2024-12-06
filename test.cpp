#include <iostream>
#include <stack>

using namespace std;

int peoples[500'000];
int total;
int answer;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	cin >> total;

	for (int i = 0; i < total; ++i) {
		cin >> peoples[i];
	}
	
	stack<pair<int,int>> s;

	s.push(make_pair(peoples[0],0));

	for (int i = 1; i < total; ++i) {
		while (!s.empty()) {
			if (s.top().first < peoples[i]) {
				answer += s.top().second + 1;
				s.pop();
			}
			else if (s.top().first == peoples[i]) {
				int can_see = s.top().second;
				s.push(make_pair(peoples[i], can_see + 1));
				break;
			}
			else {
				s.push(make_pair(peoples[i], 1));
				break;
			}
		}
		if (s.empty()) s.push(make_pair(peoples[i], 0));
	}
	while (!s.empty()) {
		answer+=s.top().second;
		s.pop();
	}
	cout << answer;
}