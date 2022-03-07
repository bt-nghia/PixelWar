int maxThree(int a, int b, int c) {
    if(a>=b && a>=c) {return a;}
    if(b>=c && b>=c) {return b;}
    if(c>=a && c>=b) {return c;}
}