#include <bits/stdc++.h>

using namespace std;

int main() {
    // int m, n = 0;
    // cin >> m;
    // int x = m/2;
    // n = x * 2;
    // n = [m/2] * 2
    int n;
    cin >> n;
    int x = n/2;
    n = x * 2;
    vector<vector<string>> ans(n+1);
    ans[0] = {};
    ans[2] = {"()"};
    for(int i = 4; i <= n; i+=2) {
        for(auto str : ans[i-2]) {
            ans[i].push_back("(" + str + ")");
        }
        for(int j = 2; j <= i; j+=2) {
            for(auto str1 : ans[j]) {
                for(auto str2 : ans[i-j]) {
                    ans[i].push_back(str1+str2);
                }
            }
        }
        sort(ans[i].begin(), ans[i].end());
    }
    for(int i = 2; i <= n; i+=2) {
        cout << ans[i][0] << "\n";
        for(int j = 1; j < ans[i].size(); j++) {
            if(ans[i][j]!=ans[i][j-1]) {cout << ans[i][j] << "\n";}
        }
    }
    return 0;
}