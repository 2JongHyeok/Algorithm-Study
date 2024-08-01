#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <array>
#include <queue>

using namespace std;

queue<int> q;

int M, N, K;
int counts;

void find_nears(int** arr) {
	int x = q.front()%M;
	int y = q.front()/M;
	q.pop();
	if (arr[y][x] == 0)
		return;
	arr[y][x] = 0;
	int xp1, xm1, yp1, ym1;
	if (x + 1 == M)
		xp1 = x;
	else xp1 = x + 1;
	if (x-1 < 0)
		xm1 = 0;
	else
		xm1 = x - 1;
	if (y + 1 == N)
		yp1 = y;
	else yp1 = y + 1;
	if (y-1 < 0)
		ym1 = 0;
	else
		ym1 = y - 1;
	if (arr[y][xp1] == 1) {
		q.push(y * M + xp1);
	}
	if (arr[y][xm1] == 1) {
		q.push(y * M + xm1);
	}
	if (arr[yp1][x] == 1) {
		q.push(yp1 * M + x);
	}
	if (arr[ym1][x] == 1) {
		q.push(ym1 * M + x);
	}
	while (!q.empty()) {
		find_nears(arr);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	cin >> T;
	for (int test = 0; test < T; ++test) {
		cin >> M >> N >> K;
		int** arr = new int* [N];
		for (int i = 0; i < N; ++i) {
			arr[i] = new int [M]();
		}
		for (int i = 0; i < K; ++i) {
			int X, Y;
			cin >> X >> Y;
			arr[Y][X] = 1;
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (arr[i][j] == 1) {
					q.push(i * M + j);
					find_nears(arr);
					counts++;
				}
			}
		}
		cout << counts << "\n";
		counts = 0;
	}
}