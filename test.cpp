#include <iostream>

using namespace std;
long long DP[1001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		if (a <= b ? cout << "No" : cout << "Yes");
	}
}	
 