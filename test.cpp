#include <iostream>
#include <set>

using namespace std;

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    multiset<pair<int, int>> ms;

    int N;
    cin >> N;

    int num;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        if (num == 0) {
            if (ms.size() == 0) {
                cout << "0\n";
                continue;
            }
            if ((*ms.begin()).second == 0) {
                cout <<"-"<< (*ms.begin()).first<<"\n";
            }
            else
                cout << (*ms.begin()).first<<"\n";
            ms.erase(ms.begin());
        }
        else {
            if (num < 0) {
                ms.insert(make_pair(num*-1, 0));

            }
            else {
                ms.insert(make_pair(num, 1));
            }
        }
    }

}