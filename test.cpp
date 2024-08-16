#include <iostream>
#include <vector>
#include <set>

using namespace std;
int N, M;

vector<int> visited(9, 0);
vector<int> v(9, 0);
set<int>s;
void back_tracking(int n, int cnt) {

    if (n == M) {
        for (int num : v) {
            if (num == 0)
                break;
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = cnt; i <= N; ++i) {
        if (visited[i] == 1)
            continue;
        visited[i] = 1;
        v[n] = i;
        back_tracking(n + 1, i+1);
        visited[i] = 0;
    }
}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> N >> M;
    back_tracking(0,1);
}