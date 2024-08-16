#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
int N, M;

vector<int> v(9, 0);
vector<int> visited(9,0);
vector<int> numbers(9, INT_MAX);

void back_tracking(int n, int count) {

	if (n == M) {
		for (int num : v) {
			if (num == 0)
				break;
			cout << num << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = count; i < N; ++i) {
		if (visited[i] == 1)continue;
		v[n] = numbers[i];
		visited[i] = 1;
		back_tracking(n + 1, i+1);
		visited[i] = 0;
	}
}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> numbers[i];
	}
	sort(numbers.begin(), numbers.end());
	back_tracking(0, 0);
}