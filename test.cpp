#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N, M;
	cin >>N>> M;
	int num = 0;
	unordered_map<string, int> um;
	vector<string> v;
	string s;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		um[s] = 1;
	}
	for (int i = 0; i < M; ++i) {
		cin >> s;
		if (um[s] != 0) {
			v.emplace_back(s);
			num++;
		}
	}
	sort(v.begin(), v.end());
	cout << num << "\n";
	for (string st : v) {
		cout << st << "\n";
	}
}