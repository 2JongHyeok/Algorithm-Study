#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int arr[1000001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> v;
	for (int i = 1; i <= N; ++i)
		v.emplace_back(i);
	int i = 1;
	int num = 0;
	cout << "<";
	while (v.size() != 1) {
		if (i % K == 0) {
			cout << v[num] << ", ";
			v.erase(v.begin() + num);
			num--;
		}

		i++;
		if (num >= v.size() - 1)
			num = 0;
		else
			num++;
	}
	cout << v[0];
	cout << ">";
}