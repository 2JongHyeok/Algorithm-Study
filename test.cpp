#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int M;
	cin >> M;
	int result = 0;
	string s;
	int a;
	for (int i = 0; i < M; ++i) {
		cin >> s;
		if (s == "add") {
			cin >> a;
			result |= (1 << a);
		}
		else if (s == "remove") {
			cin >> a;
			result &= ~(1 << a);
		}
		else if (s == "check") {
			cin >> a;
			if (result & (1 << a)) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (s == "toggle") {
			cin >> a;
			result ^= (1 << a);
		}
		else if (s == "all") {
			result = (1 << 21) - 1;
		}
		else if (s == "empty") {
			result = 0;
		}

	}
	
}