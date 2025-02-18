#include <iostream>

using namespace std;

long long MOD = 1'000'000'007;

long long cal(long long a, long long b) {
	if (b == 1) return a;
	long long val = cal(a, b/2);
	if (b % 2 == 0) {
		return (val * val)%MOD;
	}
	else {
		return ((val * val)%MOD * a) % MOD;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int M;
	cin >> M;
	
	long long answer = 0;

	for (int i = 0; i < M; ++i) {
		int N, S;
		cin >> N >> S;
		answer += (cal(N, MOD - 2) * S) % MOD;
		answer %= MOD;
	}
	cout << answer;
}