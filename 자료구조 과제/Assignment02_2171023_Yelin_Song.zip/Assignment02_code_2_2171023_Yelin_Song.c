#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#define X 3
#define Y 3
#define Z 3



double addition_3D(double ***A, double ***B,double ***C){

    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            for(int k=0; k<Z; k++){
                *(*(*(C+i)+j)+k)=*(*(*(A+i)+j)+k)+*(*(*(B+i)+j)+k);

            }

        }
    }
    return ***C;
}
void print_array(double ***S){

    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
             for(int k=0; k<Z; k++){
                 printf("%lf ",S[i][j][k]);
                 }
              printf("\n");
             }
        printf("\n");
        }
        printf("\n");
    }


int main() {
    srand(time(NULL));
    double ***A = (double***)malloc(X * sizeof(double **));
    double ***B = (double***)malloc(X * sizeof(double **));
    double ***C = (double***)malloc(X * sizeof(double **));



    for (int i = 0; i < X; i++) {
        A[i] = (double **) malloc(Y * sizeof(double *));
        B[i] = (double **) malloc(Y * sizeof(double *));
        C[i] = (double **) malloc(Y * sizeof(double *));
        for (int j = 0; j < Y; j++) {
            A[i][j] = (double *) malloc(Z * sizeof(double));
            B[i][j] = (double *) malloc(Z * sizeof(double));
            C[i][j] = (double *) malloc(Z * sizeof(double));
        }
    }
    if(A==NULL||B==NULL){
        fprintf(stderr,"메모리가 부족해서 할당할 수 없음\n");
        exit(1);
    }
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < Z; k++) {
                A[i][j][k] = rand() % 99 + 1;
                B[i][j][k] = rand() % 99 + 1;
            }
        }
    }


    addition_3D(A, B, C);
    printf("A \n");
    print_array(A);
    printf("B \n");
    print_array(B);
    printf("A+B의 합: \n");
    print_array(C);
    if(A!=NULL&&B!=NULL&&C!=NULL){
        for(int i=0; i<X; i++) {
            for (int j = 0; j < Y; j++) {
                free(A[i][j]);
                free(B[i][j]);
                free(C[i][j]);
            }
            free(A[i]);
            free(B[i]);
            free(C[i]);
        }

    }


    return 0;
}