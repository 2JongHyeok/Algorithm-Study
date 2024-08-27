#include <iostream>
#include <queue>
#include <map>


using namespace std;
map<long long, bool> visited;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int A, B;
	cin >> A >> B;
	queue<pair<long long, long long>> q;

	q.push(make_pair(A, 1));
	visited[A] = true;
	
	int answer = -1;

	while (!q.empty()) {
		long long num = q.front().first;
		int count = q.front().second;
		q.pop();
		if (num * 2 <= 1'000'000'000) {
			if (num * 2 == B) {
				answer = count+1;
				break;
			}
			if (!visited[num * 2]) {
				visited[num * 2] = true;
				q.push(make_pair(num * 2, count + 1));
			}
		}
		if (num * 10 + 1 <= 1'000'000'000) {
			if (num * 10+1 == B) {
				answer = count+1;
				break;
			}
			if (!visited[num * 10 + 1]) {
				visited[num * 10 + 1] = true;
				q.push(make_pair(num * 10 + 1, count + 1));
			}
		}
	}
	cout << answer;
}