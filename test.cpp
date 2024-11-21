#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	string s;
	string bomb;
	cin >> s >> bomb;
	int now = bomb.size()-1;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == bomb[now]) {

		}
	}

	stack<char> st;
}