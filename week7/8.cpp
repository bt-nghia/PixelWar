int** transpose(int** matrix, int nRows, int nCols) {
    int** tmat = new int*[nCols];
    for(int i = 0; i < nCols; i++) {tmat[i] = new int[nRows];}
    for(int i = 0; i < nRows; i++) {
        for(int j = 0; j < nCols; j++) {
            tmat[j][i] = matrix[i][j];
        }
    }
    return tmat;
}