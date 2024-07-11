#include <iostream>
int arr[1000001] = { 0 };

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	arr[1] = 1;
	for (int i = 2; i < 1000; i++)
	{
		for (int j = i * i; j < 1000001; j += i)
		{
			if (arr[j] != 0)
				continue;
			arr[j] = 1;
		}
	}
	int N, M;
	std::cin >> M >> N;
	for (int i = M; i <= N; i++)
	{
		if (arr[i] == 0)
			std::cout << i << "\n";
	}

}