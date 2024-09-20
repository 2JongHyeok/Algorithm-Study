#include <iostream>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n;

	while (true) {
		cin >> n;
		if (n == 0)
			break;
		
		long long answer = 0;
		for (int i = 1; i <= n; ++i) {
			answer += i;
		}
		cout << answer<<"\n";
	}
}