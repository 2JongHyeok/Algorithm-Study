#include <iostream>


using namespace std;


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, M, B;
	cin >> N >> M >> B;
	int* arr = new int[N * M];
	int total = 0;
	int max = 0;
	for (int i = 0; i < N * M; ++i) {
		cin >> arr[i];
		total += arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	total += B;
	while (max * N * M > total) {
		max--;
	}
	int total_time = INT_MAX;
	int now_time = 0;
	while (true) {
		for (int i = 0; i < N * M; ++i) {
			if (arr[i] < max) {
				now_time += max - arr[i];
			}
			else if (arr[i] > max) {
				now_time += 2 * ( arr[i]-max);
			}
		}
		if (now_time < total_time)
			total_time = now_time;
		else {
			max++;
			break;
		}
		max--;
		now_time = 0;
	}
	cout << total_time << " " << max;
}