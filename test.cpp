#include <iostream>
#include <vector>

using namespace std;

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int H, W;
    cin >> H >> W;

    vector<int> v;
    int block;
    int maxH = 0;
    int midW = 0;
    for (int i = 0; i < W; ++i) {
        cin >> block;
        v.emplace_back(block);
        if (maxH < block) {
            maxH = block;
            midW = i;
        }
    }

    int firstH = v[0];
    int result = 0;
    for (int i = 0; i < midW; ++i) {
        if (firstH < v[i]) {
            firstH = v[i];
        }
        else {
            result += firstH - v[i];
        }
    }
    firstH = v[W - 1];
    for (int i = W - 1; i > midW; --i) {
        if (firstH < v[i]) {
            firstH = v[i];
        }
        else {
            result += firstH - v[i];
        }
    }

    cout << result;

}