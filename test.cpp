#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<vector<long long>> v(N, vector<long long>(K + 1, 0));

	int W, V;
	cin >> W >> V;

	for (int i = W; i < K + 1; ++i) {
		v[0][i] = V;
	}

	for (int i = 1; i < N; ++i) {
		cin >> W >> V;
		for (int j = 0; j < K+1; ++j) {
			v[i][j] = v[i - 1][j];
		}
		for (int j = 0; j + W < K + 1; ++j) {
			if (v[i-1][j + W] < v[i - 1][j] + V) {
				v[i][j + W] = v[i - 1][j] + V;
			}
		}
	}
	cout << v[N-1][K];
}	
 