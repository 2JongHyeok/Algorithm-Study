#include <iostream>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int a, b, c;
	cin >> a >> b >> c;
	if (a < b) {
		if (b < c)
			cout << b;
		else {
			if (a < c)
				cout << c;
			else
				cout << a;
		}
	}
	else {
		if (a < c)
			cout << a;
		else {
			if (b < c)
				cout << c;
			else
				cout << b;
		}
	}
}