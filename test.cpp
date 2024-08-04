#include <iostream>
#include <queue>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	priority_queue<int> pq;

	int N;
	int num;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		if (num == 0) {
			if (pq.empty()) {
				cout << "0\n";
				continue;
			}
			num = pq.top();
			pq.pop();
			cout << pq.size()<<"\n";
			//cout << num << "\n";
		}
		else
			pq.push(num);
	}
}