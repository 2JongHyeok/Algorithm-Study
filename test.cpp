	#include <iostream>
	#include <vector>
	#include <algorithm>
	#include <cmath>

	using namespace std;
	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(NULL); 
		std::cout.tie(NULL);
		vector<int> v;
		int N;
		cin >> N;
		if (N == 0) {
			cout << "0";
		}
		else {
			for (int i = 0; i < N; ++i) {
				int a;
				cin >> a;
				v.emplace_back(a);
			}
			std::sort(v.begin(), v.end());
			int erase_size = std::lround(N * 0.15);
			int sum = 0;
			for (int i = erase_size; i < N - erase_size; ++i) {
				sum += v[i];
			}
			cout << std::lround(float(sum) / (N - (erase_size * 2)));
		}
	}