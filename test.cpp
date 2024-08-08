#include <iostream>
#include <queue>
#include <set>
using namespace std;


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, K;
	cin >> N >> K;

	queue<int> q;
	set<int> s;
	s.insert(N);
	q.push(N);
	int now;
	int answer = 0;
	int times[200001] = { 1 };

	while (true) {
		now = q.front();
		q.pop();
		if (times[answer] <= 0) {
			answer++;
		}
		if (now == K)
			break;
		times[answer]--;

		if (s.find(now * 2) == s.end()) {
			if (now * 2 <= 200000) {
				s.insert(now * 2);
				q.push(now * 2);
				times[answer + 1]++;
			}
		}
		if (s.find(now +1) == s.end()) {
			if (now + 1 <= 100000) {
				s.insert(now + 1);
				q.push(now + 1);
				times[answer + 1]++;
			}
		}
		if (s.find(now - 1) == s.end()) {
			if (now - 1 >= 0) {
				s.insert(now - 1);
				q.push(now - 1);
				times[answer + 1]++;
			}
		}
	}
	cout << answer;
}
