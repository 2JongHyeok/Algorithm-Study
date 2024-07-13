#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	cin >> N;
	stack<int>s;
	s.push(1);
	string str = "+";
	bool NO = false;
	int numbers = 2;
	for (int i = 1; i <= N; ++i) {
		int num;
		cin >> num;
		if (s.empty()) {
			if (num >= numbers) {
				s.push(numbers++);
				str += "+";
			}
		}
		if (num > s.top()) {
			while (num > s.top()) {
				s.push(numbers++);
				str += "+";
			}
			str += "-";
			s.pop();
		}
		else if (num == s.top()) {
			str += "-";
			s.pop();
		}
		else {
			NO = true;
		}
	}
	if (NO) {
		cout << "NO";
	}
	else {
		for (char c : str) {
			cout << c << "\n";
		}
	}
}