#include <iostream>
#include <vector>

using namespace std;

vector<int> Choose(13);
vector<int> numbers(13);
int Total;

void FIND(int now, int count)
{
	for (int i = count + 1; i < Total; ++i) {
		Choose[now] = numbers[i];
		if (Total - i - 1 < 5 - now) break;
		if (now == 5) {
			for (int j = 0; j < 6; ++j) {
				cout << Choose[j] << " ";
			}
			cout << "\n";
		}
		else {
			FIND(now + 1, i);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (true) {
		cin >> Total;
		if (Total == 0)break;
		for (int i = 0; i < Total; ++i) cin >> numbers[i];
		FIND(0, -1);
		cout << "\n";
	}
}