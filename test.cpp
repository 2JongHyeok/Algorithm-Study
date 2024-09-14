#include <iostream>

using namespace std;
long long DP[1001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int num = 1;
	int count = 0;
	for (int i = 1; i <= 1000; ++i) {
		DP[i] = DP[i-1] + num;
		count++;
		if (num == count) {
			num++;
			count = 0;
		}
	}
	int start, end;
	cin >> start >> end;
	cout << DP[end] - DP[start - 1];
}	
 