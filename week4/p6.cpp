double calculate (double num1, char operat, double num2) {
    double ans = 0;
    switch(operat) {
        case '+':
            ans = num1+num2; break;
        case '-':
            ans = num1-num2; break;
        case '*':
            ans = num1*num2; break;
        case '/':
            ans = num1/num2; break;
    }
    return ans;
}