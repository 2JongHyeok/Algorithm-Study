#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N, M;
vector<int> v(9, 0);
set<int> numbers;

void back_tracking(int n) {
	if (n == M) {
		for (int i = 0; i < n; ++i) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int num : numbers) {
		v[n] = num;
		back_tracking(n + 1);
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
		numbers.insert(num);
	}

	back_tracking(0);
}