#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;
int arr[100'001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int num;
	arr[0] = 0;
	for (int i = 1; i <= N; ++i) {
		cin >> num;
		arr[i] = arr[i - 1] + num;
	}
	int start, end;
	for (int i = 0; i < M; ++i) {
		cin >> start >> end;
		cout << arr[end] - arr[start-1] << "\n";
	}
}