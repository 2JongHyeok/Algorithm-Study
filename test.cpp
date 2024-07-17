#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	cin >> N;
	vector<int>v;
	int num;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		v.emplace_back(num);
	}
	sort(v.begin(), v.end());
	int sum=0;
	int result=0;
	for (int a : v) {
		sum += a;
		result += sum;
	}
	cout << result;
}