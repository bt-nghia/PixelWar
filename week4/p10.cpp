string toLower (string s) {
    string ans = "";
    for(int i = 0; i < s.length(); i++) {
        ans+=tolower(s[i]);
    }
    return ans;
}