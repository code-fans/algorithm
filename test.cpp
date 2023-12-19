#include <stdio.h>

int matrix[2][1001];
int main()
{
    int row, temp;
    scanf("%d", &row);
    int * curRow, * preRow;
    scanf("%d", &matrix[0][0]);
    for(int i=1; i<row; i++){
        curRow = matrix[i%2];
        preRow = matrix[(i+1)%2];
        for(int j=0; j<=i; j++){
            scanf("%d", &temp);
            if(j==0)
                curRow[j] = temp + preRow[j];
            else
                curRow[j] = temp + (preRow[j]>preRow[j-1]?preRow[j] :preRow[j-1]);
        }
    }
    int maxNum = curRow[0];
    for(int i=1; i<row; i++){
        if(maxNum < curRow[i])
            maxNum = curRow[i];
    }
    printf("%d", maxNum);
    return 0;
}