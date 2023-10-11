#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COLS 3
#define MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
}element;

typedef struct SparseMatrix{
    element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
}SparseMatrix;

SparseMatrix bt;

SparseMatrix matrix2(SparseMatrix b){


    int bt_index=0;
    bt.rows=b.cols;
    bt.cols=b.rows;
    bt.terms=b.terms;
    for(int i=0; i<b.cols; i++) {
        for (int j = 0; j < b.terms; j++) {
            if (b.data[j].col == i) {
                bt.data[bt_index].row = b.data[j].col;
                bt.data[bt_index].col = b.data[j].row;
                bt.data[bt_index].value = b.data[j].value;
                bt_index++;
            }
        }
    }

    return bt;
}

void matrix_print(SparseMatrix a) {
    printf("======================\n");
    for (int i = 0; i < a.terms; i++) {
        printf("%d,%d,%d \n", a.data[i].row, a.data[i].col, a.data[i].value);
    }
    printf("======================\n");
}

void matrix_printf_s(SparseMatrix a){
    int k=0;
    if(a.terms>0) {
        for (int i = 0; i < a.rows; i++) {
            for (int j = 0; j < a.cols; j++) {
                if (a.data[k].row == i && a.data[k].col == j) {
                    printf("%d ", a.data[k].value);
                    k++;
                } else
                    printf("0 ");
            }
            printf("\n");
        }
    }


}


int main(){
    SparseMatrix b = {{
            {0, 3, 7},
            {1, 0, 9},
            {1, 5, 8},
            {3, 0, 6},
            {3, 1, 5},
            {4, 5, 1},
            {5, 2, 2}},
            6,
            6,
            7};
    bt= matrix2(b);
    printf("dense matrix \n");
    printf("B= \n");
    matrix_print(b);
    printf("B^t= \n");
    matrix_print(bt);
    printf("sparse matrix \n");
    printf("B= \n");
    matrix_printf_s(b);
    printf("\n B^t= \n");
    matrix_printf_s(bt);

    return 0;
}
