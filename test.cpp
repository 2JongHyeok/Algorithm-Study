#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    string s;
    cin >> s;
    stack<int> st;
    int now = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == ')') {
            st.push(-1);
        }
        else if (s[i] == '(') {
            now = st.top();
            if (now == -1) {
                st.pop();
                --i;
                continue;
            }
            st.pop();
            st.pop();
            now *= int(s[--i]-'0');
            if (!st.empty()) {
                if (st.top() != -1) {
                    int adds = st.top();
                    st.pop();
                    st.push(now+adds);
                    continue;
                }
            }
            st.push(now);
        }
        else {
            if (st.empty()) {
                st.push(1);
                continue;
            }
            if (st.top() == -1)
                st.push(1);
            else {
                int temp = st.top();
                st.pop();
                st.push(temp + 1);
            }
        }
    }
    if (st.empty()) {
        cout << "0";
    }
    else {
        cout << st.top();
    }
}