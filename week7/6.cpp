int* merge(int* firstArr, int lenArr1, int* secondArr, int lenArr2) {
    int n = lenArr1 + lenArr2;
    int* merge = new int[n];
    int i = 0;
    int j = 0;
    int index = 0;
    bool incr = true;
    if((lenArr1 > 1 && firstArr[0] > firstArr[1]) || (lenArr2 > 1 && secondArr[0] > secondArr[1])) {incr = false;}
    if(incr) {
        while (i < lenArr1 || j < lenArr2) {
            if(j==lenArr2 && i<lenArr1) {
                merge[index] = firstArr[i];
                i++;
                index++;
            }
            else if(i==lenArr1 && j<lenArr2) {
                merge[index] = secondArr[j];
                j++;
                index++;
            }
            else {
                if(firstArr[i] >= secondArr[j]) {
                    merge[index] = secondArr[j];
                    j++;
                    index++;
                }
                else {
                    merge[index] = firstArr[i];
                    i++;
                    index++;
                }
            }
        }
    }
    else {
        while (i < lenArr1 || j < lenArr2) {
            if(j==lenArr2 && i<lenArr1) {
                merge[index] = firstArr[i];
                i++;
                index++;
            }
            else if(i==lenArr1 && j<lenArr2) {
                merge[index] = secondArr[j];
                j++;
                index++;
            }
            else {
                if(firstArr[i] >= secondArr[j]) {
                    merge[index] = secondArr[i];
                    i++;
                    index++;
                }
                else {
                    merge[index] = firstArr[j];
                    j++;
                    index++;
                }
            }
        }
    }
    return merge;
}