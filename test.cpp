#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N;
	vector<int> v;
	int max = 0;
	int num;
	int fruits[2]{0,0};
	int count = 0;
	int continued = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		v.emplace_back(num);
		if (count == 0) {
			fruits[count] = num;
			count++;
			continued++;
		}
		else if (count == 1) {
			if (fruits[count - 1] != num) {
				fruits[count] = num;
				count++;
			}
			continued++;
		}
		else {
			if (fruits[0] == num) {
				continued++;
			}
			else if (fruits[1] == num) {
				continued++;
			}
			else {
				if (max < continued) {
					max = continued;
				}
				int prev = v[i - 1];
				if (v[i - 1] == fruits[0]) {
					fruits[1] = num;
				}
				else {
					fruits[0] = num;
				}
				continued = 0;
				for (int j = i-1; j >= 0; --j) {
					if (v[j] == prev) {
						continued++;
					}
					else
						break;
				}
				continued++;
			}
		}
	}
	if (max < continued)
		max = continued;
	cout << max;
}