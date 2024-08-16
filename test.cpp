#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int W[4] = { 0,0,1,-1 };
int H[4] = { 1,-1,0,0 };

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> paper(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> paper[i][j];
        }
    }

    queue<pair<int,int>> q;

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int count = 0;
    int maxW = 0;
    int nowW = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (paper[i][j] == 0) continue;
            if (visited[i][j]) continue;
            q.push(make_pair(i, j));
            nowW = 0;
            count++;
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                if (visited[p.first][p.second]) continue;
                visited[p.first][p.second] = true;
                nowW++;
                for (int k = 0; k < 4; ++k) {
                    if (p.first + H[k] < 0) continue;
                    if (p.first + H[k] >= n) continue;
                    if (p.second + W[k] <0) continue;
                    if (p.second + W[k] >= m) continue;
                    if (visited[p.first + H[k]][p.second + W[k]]) continue;
                    if (paper[p.first + H[k]][p.second + W[k]] == 0)continue;
                    q.push(make_pair(p.first + H[k], p.second + W[k]));
                }
            }
            if (maxW < nowW)
                maxW = nowW;
        }
    }

    cout << count << "\n" << maxW;
}
