#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;
long long arr[1001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	cin >> N;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 5;
	arr[5] = 8;
	for (int i = 6; i <= N; ++i) {
		arr[i] = arr[i - 1]%10007 + arr[i - 2]%10007;
		arr[i] %= 10007;
	}
	cout << arr[N];
}