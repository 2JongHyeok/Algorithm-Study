#include <iostream>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	long long n = 0;
	for (int i = 0; i < 5; ++i) {
		long long num;
		cin >> num;
		n += num;
	}
	cout << n;
}