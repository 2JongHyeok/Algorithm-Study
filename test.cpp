#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

int arr[1000001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T, N;
	cin >> T;
	string name, part;
	unordered_map<string, int> uMap;
	for (int test = 0; test < T; ++test) {
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> name >> part;
			uMap[part]++;
		}
		int sum = 1;
		for (pair<string, int> p : uMap) {
			sum *= (p.second+1);
		}

		cout << sum-1 << "\n";
		uMap.clear();
	}
}