#include <iostream>
using namespace std;

int counts[256] = {0,};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s;

    int maxCount = -1;
    while (cin >> s) {
        for (int i = 0; i < s.length(); i++) {
            counts[s[i]]++;
            if (counts[s[i]] > maxCount) {
                maxCount = counts[s[i]];
            }
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        if (counts[c] == maxCount) {
            printf("%c", c);
        }
    }

    return 0;
}