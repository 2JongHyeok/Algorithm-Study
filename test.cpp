#include <iostream>

using namespace std;

long long gcd(long long  a, long long b) {
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long lcm(long long a, long long b)
{
	return a * b / gcd(a, b);
}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 0; test < T; ++test) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int max_x = lcm(M, N) / M;
		int max_y = lcm(M, N) / N;
		x--;
		y--;


		int result = -1;

		if (M > N) {
			for (int i = 0; i < max_x; ++i) {
				if ((M * i + x) % N == y) {
					result = M * i + x;
					break;
				}
			}
		}
		else {
			for (int i = 0; i < max_y; ++i) {
				if ((N * i + y) % M == x) {
					result = N * i + y;
					break;
				}
			}
		}
		cout << result+1<<"\n";
	}
}