#include<stdio.h>
#include<stdlib.h>

int **createMatrix(int rows, int cols){
    int **matrix=(int**)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++){
        matrix[i]=(int*)malloc(cols*sizeof(int));
    }
    return matrix;
}

void inputMatrix(int **matrix, int rows, int cols){
    printf("Enter elements (%dx%d:)\n",rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("Element [%d][%d]: ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
}

int** multiplyMatrices(int **A, int **B, int r1, int c1, int c2){
    int **C = createMatrix(r1,c2);
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            C[i][j]=0;
            for(int k=0;k<c1;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return C;
}

void displayMatrix(int **matrix, int rows, int cols){
    printf("Matrix (%dx%d):\n",rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int r1,c1,r2,c2;
    printf("Enter the rows and columns for Matrix A: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter the rows and columns for Matrix B: ");
    scanf("%d %d",&r2,&c2);
    if(c1!=r2){
        printf("Matrix multiplication not possible (columns of A != rows of B).\n");
        return 1;
    }
    int **A=createMatrix(r1,c1), **B=cleateMatrix(r2,c2);
    printf("\n--Input Matrix A ---\n");
    inputMatrix(A,r1,c1);
    printf("\n--Input Matrix B ---\n");
    inputMatrix(B,r2,c2);
    int **C=multiplyMatrices(A,B,r1,c1,c2);
    printf("\n-- Result Matrix (A x B) --\n");
    displayMatrix(C,r1,c2);
    for(int i=0;i<r1;i++){
        free(A[i]);
    }
    free(A);
    for(int i=0;i<r2;i++){
        free(B[i]);
    }
    free(B);
    for(int i=0;i<r1;i++){
        free(C[i]);
    }
    free(C);
    return 0;
}