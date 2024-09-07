#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> chicken;
vector<pair<int, int>> houses;
int Distance[100][2500];
int MinDistance[14][2500];
long long answer = 1e9;
void FIND(int my, int num) {
	if (num == M - 1) {
		long long pre_answer = 0;
		for (int i = 0; i < houses.size(); ++i) {
			pre_answer += min(Distance[my][i], MinDistance[num][i]);
		}
		if (answer > pre_answer)
			answer = pre_answer;
		return;
	}
	if (num < M - 1) {
		for (int i = 0; i < houses.size(); ++i) {
			MinDistance[num + 1][i] = min(MinDistance[num][i], Distance[my][i]);
		}
		for (int i = my + 1; i < chicken.size(); ++i) {
			FIND(i, num + 1);
		}
	}
}

void FIND_DISTANCE(int my) {
	for (int i = 0; i < houses.size(); ++i) {
		Distance[my][i] = abs(chicken[my].first - houses[i].first) + abs(chicken[my].second - houses[i].second);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	cin >> N >> M;
	int number;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> number;
			if (number == 1) {
				houses.emplace_back(make_pair(i, j));	
			}
			else if (number == 2) {
				chicken.emplace_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < 2500; ++i) {
		MinDistance[0][i] = int(1e9);
	}
	for (int i = 0; i < chicken.size(); ++i) {
		FIND_DISTANCE(i);
	}

	for (int i = 0; i <= chicken.size()-M; ++i) {
		FIND(i, 0);
	}
	cout << answer;
}	
 