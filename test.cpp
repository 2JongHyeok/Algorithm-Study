#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int M,N;
	cin >> M>>N;
	unordered_map<string, int> m;
	unordered_map<int,string> m2;

	for (int i = 1; i <= M; ++i) {
		string s;
		cin >> s;
		m[s]=i;
		m2[i] = s;
	}
	for (int i = 0; i < N; ++i) {
		string s;
		int a;
		cin >> s;
		if (s[0] >= 'A') {
			cout << m[s]<<"\n";
		}
		else {
			a = stoi(s);
			cout << m2[a] << "\n";
		}
	}
}