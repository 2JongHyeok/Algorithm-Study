#include <iostream>

using namespace std;

int white = 0;
int blue = 0;

int paper[128][128];

void one_color(int startX, int endX, int startY, int endY) {
	int first_color = paper[startY][startX];
	bool same = true;
	for (int i = startY; i < endY; ++i) {
		for (int j = startX; j < endX; ++j) {
			if (first_color != paper[i][j]) {
				same = false;
				break;
			}
		}
		if (!same) break;
	}
	if (!same) {
		one_color(startX, (startX+endX)/2, startY,(startY+endY)/2);
		one_color((startX + endX) / 2, endX, startY, (startY + endY) / 2);
		one_color(startX, (startX + endX) / 2, (startY + endY) / 2, endY);
		one_color((startX + endX) / 2, endX, (startY + endY) / 2, endY);
	}
	else {
		if (first_color == 1) {
			blue++;
		}
		else
			white++;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> paper[i][j];
		}
	}
	one_color(0, N, 0, N);
	cout << white << "\n";
	cout << blue;
}