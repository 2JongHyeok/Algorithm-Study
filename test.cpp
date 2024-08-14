#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    vector<pair<int,int>> v;

    int N;
    int L, H;
    int midH = 0;
    int mid = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> L >> H;
        v.emplace_back(make_pair(L, H));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        if (midH < v[i].second) {
            midH = v[i].second;
            mid = i;
        }
    }
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    bool half = false;
    int s1H = 0;
    int s2H = 0;

    for (int i = 0; i <= mid; ++i) {
        if (s1H <= v[i].second) {
            s1H = v[i].second;
            q1.push(make_pair(v[i].first, v[i].second));
        }
    }
    for (int i = N - 1; i >= mid; --i) {
        if (s2H <= v[i].second) {
            s2H = v[i].second;
            q2.push(make_pair(v[i].first, v[i].second));
        }
    }
    int prevL = 0;
    int prevH = 0;
    int nowL = 0;
    int nowH = 0;

    int answer = 0;

    while (!q1.empty()) {
        prevL = nowL;
        prevH = nowH;
        nowL = q1.front().first;
        nowH= q1.front().second;
        answer += (nowL - prevL) * prevH;
        q1.pop();
    }
    prevL = 0;
    prevH = 0;
    nowL = 0;
    nowH = 0;
    while (!q2.empty()) {
        prevL = nowL;
        prevH = nowH;
        nowL = q2.front().first;
        nowH = q2.front().second;
        answer += (prevL - nowL) * prevH;
        q2.pop();
    }
    answer += midH;
    cout << answer;
}