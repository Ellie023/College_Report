1. Assignment02_code_1_2171023_송예린.c
C language로 작성된 코드이다. danse matrix를 가지고 transpose matrix를 만들고 다시 Sparse Matrix로 출력하였다.
1)typedef struct element
matrix에서 row,col,value 값을 저장한다.
2) typedef struct SparseMatrix
구조체 element를 포함하고 있어서 이 구조체를 사용하여 row,col,value 값도 가져올 수 있다. rows는 행의 개수, cols는 열의 개수 terms는 0이 아닌 값의 항에 값이다.
3)SparseMatrix bt;
 함수와 main()에서 같이 사용하기 위해 전역으로 선언하였다 전치행렬을 나타내는 구조체이다.
4) SparseMatrix matrix2(SparseMatrix b)
dense matix를 가져와서 전치행렬로 바꿔준다. b의 0열부터 순서대로 저장해야 b^t의 0행부터 출력되기 때문에 0열부터 저장되게 코드를 작성하였고 바뀐 전치행렬 bt를 리턴하였다.
5)void matrix_print(SparseMatrix a)
b와 b^t의 dense matrix를 출력해준다.
6)void matrix_printf_s(SparseMatrix a)
dense matrix를 sparse matrix로 출력하는 역할을 한다. row를 나타내는 i와 col를 나타내는 j를 증가시켜서 구조체 값과 일치하면 0이 아닌 항을 출력하고 일치하지 않으면 0을 출력한다.
7) int main()
B matrix를 dense matrix 식으로 값을 입력하였다. 각각의 함수를 호출해서 전치행렬로 바꾸고 출력하는 식으로 작성하였다.

2. 1. Assignment02_code_2_2171023_송예린.c
C language로 작성된 코드이다. double 형 3중 포인터로 3d 배열을 표현하고 2개의 배열을 더하여 출력하는 코드이다.

1) double addition_3D(double ***A, double ***B,double ***C)
2개의 포인터에서 같은 위치(행,열,높이) 항들을  더해주는 역할을 한다. 더한 값 c 포인터를 리턴한다.
2) void print_array(double ***S)
포인터를 호출하여 출력한다.
3) int main()
3개의 3중 포인터를 동적메모리로 할당해주고 각 노드에 랜덤 값을 입력해준다. 함수를 호출해서 2개의 포인터를 더해주고 더한 포인터를 함수를 호출해서 출력한다. 출력 후 동적 메모리를 반납해준다.
