#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
		if (a.first != b.first)
			return a.first < b.first;
		return a.second > b.second;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	cin >> N;

	vector<int> arr1, arr2;

	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		arr1.emplace_back(tmp);
	}
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int tmp;
		cin >> tmp;
		arr2.emplace_back(tmp);
	}
	vector<int> answer;
	int max1_index = -1;
	int max2_index = -1;
	while (true) {
		priority_queue<pair<int, int>,vector<pair<int,int>>, cmp> pq1, pq2;
		int max1 = -1;
		int	max2 = -1;
		for (int i = max1_index + 1; i < arr1.size(); ++i) {
			pq1.push(make_pair(arr1[i], i));
		}
		for (int i = max2_index + 1; i < arr2.size(); ++i) {
			pq2.push(make_pair(arr2[i], i));
		}

		if (!pq1.empty()) {
			max1 = pq1.top().first;
			max1_index = pq1.top().second;
		}
		if (!pq2.empty()) {
			max2 = pq2.top().first;
			max2_index = pq2.top().second;
		}

		int finished = true;

		while (!pq1.empty() && !pq2.empty()) {
			if (max1 > max2) {
				max1 = pq1.top().first;
				max1_index = pq1.top().second;
				pq1.pop();
			}
			else if (max2 > max1) {
				max2 = pq2.top().first;
				max2_index = pq2.top().second;
				pq2.pop();
			}
			if (max1 == max2) {
				finished = false;
				answer.emplace_back(max1);
				break;
			}
		}
		if (finished) break;
	}
	if (answer.size() == 0) cout << 0;
	else {
		cout << answer.size() << "\n";
		for (int i = 0; i < answer.size(); ++i)
			cout << answer[i] << " ";
	}
}	