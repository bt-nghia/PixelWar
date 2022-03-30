void rFilter(char *s) {
    // Your code goes here
    *(s) = '_';
    *(s + 1) = '\0';
    bool check = false;
    int index = 0;
    int x = 0;
    while(s[x]!='\0') {x++;}

    for(int i = x; i>= 0; i--) {
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) {index = i; break;}
    }
    for(int i = index+1; i <= x; i++) {s[i] = '_';}
}