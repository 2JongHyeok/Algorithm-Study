#include <iostream>
#include <deque>
#include <ctype.h>

using namespace std;

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string p;
		cin >> p;
		int n;
		cin >> n;
		deque<int> d;
		string numbers;
		cin >> numbers;
		int number=0;
		for (char c : numbers) {
			if (isdigit(c)) {
				number *= 10;
				number += int(c-'0');
			}
			if (c == ','||c == ']') {
				d.push_back(number);
				number = 0;
			}
		}
		bool rev = false;
		bool error = false;
		for (char c : p) {
			if (c == 'R') {
				if (rev)rev = false;
				else rev = true;
			}
			if (c == 'D') {
				if (n == 0) {
					error = true;
					break;
				}
				else {
					if (rev) d.pop_back();
					else d.pop_front();
					n--;
				}
			}
		}

		if (error) cout << "error\n";
		else {
			cout << "[";
			if (n == 0) {
				cout << "]\n";
				continue;
			}
			if (rev) {
				for (int i = 0; i < n - 1; ++i) {
					cout << d.back() << ",";
					d.pop_back();
				}
				cout << d.back() << "]\n";
			}
			else {
				for (int i = 0; i < n - 1; ++i) {
					cout << d.front() << ",";
					d.pop_front();
				}
				cout << d.front() << "]\n";
			}
		}
	}
}	