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

    int M,N;
    cin >> M >> N;

    vector<vector<int>> box(N, vector<int>(M, 0));
    queue<pair<pair<int,int>,int>> q;
    vector<vector<bool>> ripe(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> box[i][j];
            if(box[i][j] == 1)
                q.push(make_pair(make_pair(i, j), 0));
        }
    }
    int max=0;
    while (!q.empty()) {
        pair<int, int> p = q.front().first;
        int days = q.front().second;
        q.pop();
        if (ripe[p.first][p.second]) continue;
        ripe[p.first][p.second] = true;
        box[p.first][p.second] = 1;
        for (int k = 0; k < 4; ++k) {
            int x = p.second + W[k];
            int y = p.first + H[k];
            if (x < 0 || x >= M || y < 0 || y >= N) continue;
            if (ripe[y][x]) continue;
            if (box[y][x] == -1)continue;
            if (box[y][x] == 1)continue;
            q.push(make_pair(make_pair(y, x),days+1));
        }
        max = days;
    }
    for (auto a : box) {
        for (auto b : a) {
            if (b == 0) {
                cout << "-1";
                return 0;
            }
        }
    }
    cout << max;
}
