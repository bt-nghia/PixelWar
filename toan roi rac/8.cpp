#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
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
    cout << ans[n-2][0] << "\n";
    for(int i = 1; i < ans[n-2].size(); i++) {
        if(ans[n-2][i]!=ans[n-2][i-1]) {cout << ans[n-2][i] << "\n";}
    }
    cout << ans[n][0] << "\n";
    for(int i = 1; i < ans[n].size(); i++) {
        if(ans[n][i]!=ans[n][i-1]) {cout << ans[n][i] << "\n";}
    }
    return 0;
}