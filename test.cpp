	#include <iostream>
	#include <queue>
	#include <array>

	using namespace std;
	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(NULL); 
		std::cout.tie(NULL);
		int K;
		cin >> K;
		int N, M;
		for (int i = 0; i < K; ++i) {
			cin >> N >> M;
			queue<int> q;
			array<int, 9> arr{ 0 };
			int max = 0;
			int my_pro;
			for (int i = 0; i < N; ++i) {
				int num;
				cin >> num;
				q.push(num);
				if (max < num)
					max = num;
				if (i == M)
					my_pro = num;
				arr[num - 1]++;
			}
			int index = M;
			int count = 1;
			while (true) {
				int pro = q.front();
				if (index == 0) {
					if (max == my_pro) {
						cout << count << "\n";
						break;
					}
					else {
						q.pop();
						q.push(pro);
						index = q.size()-1;
						continue;
					}
				}
				if (pro == max) {
					q.pop();
					arr[max - 1]--;
					if (arr[max - 1] == 0) {
						for (int i = 8; i >=0; --i) {
							if (arr[i] > 0) {
								max = i + 1;
								break;
							}
						}
					}
					count++;
					index--;
				}
				else {
					q.pop();
					q.push(pro);
					index--;
				}

			}
		}
	}