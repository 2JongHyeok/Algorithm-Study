#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	cin >> N;
	std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
	int num;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		if (num == 0) {
			if (min_heap.size() == 0) {
				cout << "0\n";
				continue;
			}
			cout << min_heap.top() << "\n";
			min_heap.pop();
		}
		else {
			min_heap.push(num);
		}
	}
	
}