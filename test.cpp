#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

int N, M;
vector<int> v(9, 0);
vector<int> numbers(9, INT_MAX);
vector<int> visited(9, false);

void back_tracking(int n, int count) {
	if (n == M) {
		for (int i = 0; i < n; ++i) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	v[n] = -1;
	for (int i = count; i < N; ++i) {
		if (i != 0) {
			if (numbers[i] == v[n])
				continue;
		}
		if (visited[i]) continue;
		v[n] = numbers[i];
		visited[i] = true;
		back_tracking(n+1, i+1);
		visited[i] = false;

	}
}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M;
	int num;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		numbers.emplace_back(num);
	}
	sort(numbers.begin(), numbers.end());

	back_tracking(0,0);
}