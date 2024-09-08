#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N;
	cin >> N;

	long long answer = 1;
	for (int i = 1; i <= N; ++i) {
		answer *= i;
		while (true) {
			if (answer % 10 == 0) {
				answer /= 10;
			}
			else
				break;
		}
		answer %= 1'000'000'000'000;
	}
	string s = to_string(answer);
	if (s.size() > 5) {
		string new_s = "";
		for (int i = s.size() - 5; i < s.size(); ++i) {
			new_s += s[i];
		}
		s = new_s;
	}
	cout << s;
}	
 