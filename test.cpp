#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() >= s2.size() ? cout << "go" : cout << "no");
}	