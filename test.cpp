#include <iostream>
#include <cmath>

using namespace std;

int arr[100001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	int sum = 0;
	cin >> N;
	for (int i = 2; i <= N; ++i) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) {
			arr[i] =min(arr[i], arr[i / 2] + 1);
		}
		if (i % 3 == 0) {
			arr[i] =min(arr[i], arr[i / 3] + 1);
		}
	}
	cout << arr[N];	
}