#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N , K;
	cin >> N >> K;
	vector<int> v;
	int money;
	for (int i = 0; i < N; ++i) {
		cin >> money;
		v.emplace_back(money);
	}
	int count = 0;
	for (int i = v.size() - 1; i >= 0; --i) {
		if (K / v[i] > 0) {
			count += K / v[i];
			K %= v[i];
		}
		
	}

	cout << count;
}