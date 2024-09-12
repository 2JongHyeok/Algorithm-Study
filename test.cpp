#include <iostream>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = N; i >= 1; --i) {
		cout << i << "\n";
	}
	
}	
 