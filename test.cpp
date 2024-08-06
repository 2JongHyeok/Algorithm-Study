#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, r, c;
	cin >> N >> r >> c;

	int answer = 0;
	int board;

	int newR;
	int newC;

	while (N != 0) {
		board = pow(2, N - 1);
		newR = r / board;
		newC = c / board;
		r  %= board;
		c %= board;
		answer += board * board * (newR * 2 + newC);
		N -=1;
	}
	cout << answer;
}