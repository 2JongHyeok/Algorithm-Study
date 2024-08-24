#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<pair<pair<int, int>, int>> v;

	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		v.emplace_back(make_pair(make_pair(num, 0), i));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i) {
		v[i].first.second = i;
	}

	sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
			return a.second < b.second;
		}
	);

	for (int i = 0; i < n; ++i) {
		cout << v[i].first.second << " ";
	}
}