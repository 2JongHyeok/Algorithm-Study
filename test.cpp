#include <iostream>
#include <vector>
#include <set>

using namespace std;
int N, M;

vector<int> v(9, 0);

void back_tracking(int n) {

    if (n == M) {
        for (int num : v) {
            if (num == 0)
                break;
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; ++i) {
        v[n] = i;
        back_tracking(n + 1);
    }
}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> N >> M;
    back_tracking(0);
}