#include <iostream>
#include <vector>

using namespace std;
int col[15];
int total = 0;
int N;

bool check(int n)
{
	for (int i = 0; i < n; ++i) {
		if (col[i] == col[n] || abs(col[n] - col[i]) == n - i) {
			return false;
		}
	}
	return true;
}

void Find(int count)
{
	if (count == N) {
		total++;
		return;
	}
	for (int i = 0; i < N; ++i) {
		col[count] = i;
		if (check(count)) {
			Find(count + 1);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	cin >> N;

	Find(0);
	cout << total;
}