#include <iostream>
#include <set>

using namespace std;

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		multiset<int> ms;
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			char c;
			cin >> c;
			int num;
			cin >> num;
			if (c == 'I') {
				ms.insert(num);
			}
			else if (c == 'D') {
				if (ms.empty())continue;
				if (num == 1) ms.erase(--ms.end());
				if (num == -1) ms.erase(ms.begin());
			}
		}
		if (ms.empty()) cout << "EMPTY\n";
		else cout  <<*(--ms.end()) << " " << *ms.begin() <<"\n";
	}

}	