#include <iostream>

using namespace std;

int sum0 = 0;
int sum1 = 0;

void fibonacci(int n) {
	if (n == 0) {
		sum0++;
		return;
	}
	else if (n == 1) {
		sum1++;
		return;
	}
	int* arr = new int[n];
	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i < n; ++i) {
		arr[i] = arr[i-1] + arr[i -2];
	}
	sum1 = arr[n-1];
	sum0 = arr[n-2];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T, N;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		sum0 = 0;
		sum1 = 0;
		cin >> N;
		fibonacci(N);
		cout << sum0 << " " << sum1 << "\n";
	}
	
}