#include <iostream>
#include <queue>
#include <array>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int K, N;
	cin >> K >> N;
	vector<int>v;
	v.reserve(K);
	int length = 0;
	int min=1; 
	unsigned int max = 0x7FFFFFFF;
	for (int i = 0; i < K; ++i) {
		int num;
		cin >> num;
		v.emplace_back(num);
	}
	unsigned int mid;
	while (true) {
		mid = (max +min)/2;
		int sum = 0;
		for (int a : v) {
			sum += (a / mid);
		}
		if (sum < N) {
			max = mid-1;
		}
		else if (sum >= N) {
			min = mid+1;
		}
		if (min > max)
			break;
	}
	
	cout << max;
}