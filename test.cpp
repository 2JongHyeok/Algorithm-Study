#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, k;
    cin >> N >> k;
    string line[2];
    cin >> line[0] >> line[1];

    int step = 0;
    queue<pair<int,int>> q;
    vector<int> v(2,0);

    bool clear = false;

    q.push(make_pair(0, 0));
    v[0] = 1;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        if (v[step] == 0) {
            line[0][step] = '0';
            line[1][step] = '0';
            step++;
            if (v.size() == step+1) {
                v.emplace_back(0);
            }
        }
        v[step]--;
        if (line[p.first][p.second] == '0')
            continue;
        line[p.first][p.second] = '0';

        if (p.second + k > N - 1) {
            clear = true;
            break;
        }
        if (line[p.first][max((p.second - 1), 0)] == '1') {
            q.push(make_pair(p.first, max((p.second - 1), 0)));
            v[step + 1]++;
        }
        if (line[p.first][p.second+1] == '1') {
            q.push(make_pair(p.first, min((p.second + 1), N-1)));
            v[step + 1]++;
        }
        if (line[((p.first + 1)% 2)][p.second + k] == '1') {
            q.push(make_pair((p.first + 1) % 2, p.second + k));
            v[step + 1]++;
        }
    }
    if (clear) {
        cout << "1";
    }
    else {
        cout << "0";
    }


}