#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	vector<pair<int, int>> s;
	int N;
	cin >> N;
	int start, end;
	for (int i = 0; i < N; ++i) {
		cin >> start >> end;
		s.emplace_back(make_pair(start, end));
	}

	std::sort(s.begin(), s.end());

	int last_conf = -1;
	int answer = 0;
	for (auto conf : s) {
		if (conf.second <= last_conf) {
			if (conf.second == last_conf) {
				if (conf.first == conf.second) {
					answer++;
				}
			}
			last_conf = conf.second;
			continue;
		}
		if (conf.first < last_conf)
			continue;
		answer++;
		last_conf = conf.second;
	}
	cout << answer;

}
