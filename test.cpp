#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	string s;
	cin >> s;
	int num[3]{ 0 };
	int now = 0;
	int plus = 1;
	bool minus = false;
	for (char c : s) {
		if (c == '+') {
			num[1] += num[2];
			num[2] = 0;
		}
		else if (c == '-') {
			num[1] += num[2];
			num[2] = 0;
			if (minus) {
				num[0] -= num[1];
				num[1] = 0;
			}
			else {
				num[0] = num[1];
				num[1] = 0;
				minus = true;
			}
		}
		else {
			num[2] *= 10;
			num[2] += int(c-'0');
		}
	}
	num[1] += num[2];
	if (minus) {
		num[2] = 0;
		num[0] -= num[1];
	}
	else {
		num[0] = num[1];
	}
	cout << num[0];
}