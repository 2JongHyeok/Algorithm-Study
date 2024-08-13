#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<int> computeLPS(const std::string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int KMPSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int count = 0;

    vector<int> lps = computeLPS(pattern);

    int i = 0;  
    int j = 0;  

    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
            
        if (j == m) {
            count++;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return count;
}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string S;
    cin >> S;

    string pattern="IOI";

    for (int i = 1; i < N; ++i) {
        pattern += "OI";
    }

    int result = KMPSearch(S, pattern);
    
    cout << result;

    return 0;
}