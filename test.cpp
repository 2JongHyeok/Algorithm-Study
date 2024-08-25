#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	cin >> T;
	
	int D, S, L, R;
	string change;
	for (int i = 0; i < T; ++i) {
		int p[10001]{};
		queue<pair<int, string>>  q;
		int start, end;
		cin >> start >> end;
		q.push(make_pair(start, ""));
		while (true) {
			int n = q.front().first;
			string s = q.front().second;
			q.pop();
			if (n == end) {
				cout << s << "\n";
				break;
			}
			
			D = n * 2 % 10000;
			S = n - 1;
			if (S < 0) S = 9999;
			L = (n * 10)%10000 + n / 1000;
			R = n / 10 + (n % 10) * 1000;

			if (p[D] == 0) {
				q.push(make_pair(D, s + 'D'));
				p[D] = 1;
			}
			if (p[S] == 0) {
				q.push(make_pair(S, s + 'S'));
				p[S] = 1;
			}
			if (p[L] == 0) {
				q.push(make_pair(L, s + 'L'));
				p[L] = 1;
			}
			if (p[R] == 0) {
				q.push(make_pair(R, s + 'R'));
				p[R] = 1;
			}
		}
	}
}