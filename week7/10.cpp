
void rFilter(char *s) {
    // Your code goes here
    int x = 0, index = -1;
    while(s[x]!='\0') {x++;}
    for(int i = x-1; i >= 0; i--) {
        if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')) {index = i; break;}
    }
    if(index >= 0) {
        for(int i = index+1; i < x; i++) {
            s[i] = '_';
        }
    }
}
