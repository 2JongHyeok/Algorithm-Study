#include <iostream>
#include <queue>
#include <map>


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, K;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	std::vector<int> v(200'002, 100'001);
	std::cin >> N >> K;
	pq.push(std::make_pair(1, N));
	
	if (N >= K) {
		std::cout << N - K;
		return 0;
	}
	while (!pq.empty()) {
		std::pair<int, int> p = pq.top();
		pq.pop();
		if (p.second > K) {
			v[K] = std::min(v[K], p.first + p.second - K);
			continue;
		}
		if (p.second * 2 <= K + 50000) {
			if (v[p.second * 2] > p.first) {
				if (p.second * 2 == K) {
					v[p.second * 2] = p.first;
					break;
				}
				v[p.second * 2] = p.first;
				pq.push(std::make_pair(p.first, p.second * 2));
			}
		}
		if (v[p.second + 1] > p.first + 1) {
			if (p.second + 1 == K) {
				v[p.second + 1] = p.first + 1;
				break;
			}
			v[p.second + 1] = p.first + 1;
			pq.push(std::make_pair(p.first + 1, p.second + 1));
		}
		if (p.second - 1 > 0) {
			if (v[p.second - 1] > p.first + 1) {
				if (p.second - 1 == K) {
					v[p.second - 1] = p.first + 1;
					break;
				}
				v[p.second - 1] = p.first + 1;
				pq.push(std::make_pair(p.first + 1, p.second - 1));
			}
		}
	}
	std::cout << v[K] - 1;
}
