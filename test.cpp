#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	string given, wants;
	cin >> given >> wants;
	int wants_length = wants.size();
	reverse(wants.begin(), wants.end());
	stack<char> s;
	for (int i = 0; i < given.size(); ++i) {
		s.push(given[i]);
		if (s.top() == wants[0] && s.size() >= wants_length) {
			string temp;
			for (int i = 0; i < wants_length; ++i) {
				temp += s.top();
				s.pop();
			}
			if (temp != wants) {
				for (int i = wants_length-1; i >= 0; --i) {
					s.push(temp[i]);
				}
			}
		}
	}
	string answer;
	answer.reserve(1000000);
	if (s.empty()) {
		cout << "FRULA";
	}
	else {
		while (!s.empty()) {
			answer += s.top();
			s.pop();
		}
		reverse(answer.begin(), answer.end());
		cout << answer;
	}
}