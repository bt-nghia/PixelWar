string pigLatin(string word) {
    string ans = "";
    if(word[0]=='u'||word[0]=='i'||word[0]=='a'||word[0]=='e'||word[0]=='o') {
        ans+=word;
        ans+="way";
    }
    else {
        for(int i = 1; i < word.length(); i++) {
            ans+=word[i];
        }
        ans+=word[0];
        ans+="ay";
    }
    return ans;
}