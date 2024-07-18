#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N, M;
	unordered_map < string, string> um;
	string id;
	string password;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> id >> password;
		um[id] = password;
	}
	for (int i = 0; i < M; ++i) {
		cin >> id;
		cout << um[id] << "\n";
	}
}