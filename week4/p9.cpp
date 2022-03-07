void sort(float array[], int size, bool isAscending) {
    vector<float> v(size, 0);
    for(int i = 0; i < size; i++) {
        v[i] = array[i];
    }
    sort(v.begin(), v.end());
    if(isAscending) {
        for(int i = 0; i < size; i++) {
            array[i] = v[i];
        }
    }
    else {
        for(int i = 0; i < size; i++) {
            array[i] = v[size-1-i];
        }
    }
}