#include <iostream>
#include <queue>

using namespace std;
bool visited[100'001]{ false };

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int subin, sister;
	cin >> subin >> sister;

	if (subin == sister) {
		cout << "0\n0";
		return 0;
	}

	queue<pair<int,int>> q;
	int found_time = -1;
	int count = 0;

	q.push(make_pair(0, subin));
	visited[subin] = true;

	priority_queue<int> update_pos;
	int last_time = 0;
	while (!q.empty()) {
		int now_time = q.front().first;
		int now_pos = q.front().second;
		q.pop();
		if (now_time == found_time) break;
		if (last_time != now_time) {
			while (!update_pos.empty()) {
				visited[update_pos.top()] = true;
				update_pos.pop();
			}
			last_time = now_time;
		}
		if (now_pos + 1 == sister) {
			found_time = now_time + 1;
			count++;
		}
		else {
			if (now_pos < sister) {
				if (!visited[now_pos + 1]) {
					q.push(make_pair(now_time + 1, now_pos + 1));
					update_pos.push(now_pos + 1);
				}
			}
		}
		if (now_pos - 1 == sister) {
			found_time = now_time + 1;
			count++;
		}
		else {
			if (now_pos > 0) {
				if (!visited[now_pos -1]) {
					q.push(make_pair(now_time + 1, now_pos - 1));
					update_pos.push(now_pos - 1);
				}
			}
		}
		if (now_pos *2 == sister) {
			found_time = now_time + 1;
			count++;
		}
		else {
			if (now_pos * 2 < 100000) {
				if (!visited[now_pos * 2]) {
					q.push(make_pair(now_time + 1, now_pos * 2));
					update_pos.push(now_pos * 2);
				}
			}
		}
	}

	cout << found_time << "\n" << count;
}