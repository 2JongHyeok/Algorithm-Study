#include <iostream>
#include <cmath>

using namespace std;

int arr[1000001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	int results[300]{ 0 };
	results[0] = arr[0];
	results[1] = arr[0] + arr[1];
	results[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (int i = 3; i < N; ++i) {
		results[i] = max(results[i - 2] + arr[i], arr[i - 1]+ arr[i] + results[i - 3]);
	}
	cout << results[N - 1];
	
}