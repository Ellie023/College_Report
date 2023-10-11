1. Assignment04_code_1_2171023_Yelin_Song.cpp
C language로 작성된 코드이다. 스택을 circular double linked list로 구현하였다.
	
1) typedef int element
element를 int로 선언한다.
2) typedef struct StackNode 
item,llink,rlink가 들어있는 구조체를 선언한다.
3) typedef struct LinkedStackType;
노드 구조체 top를 선언한다.
4) void init(LinkedStackType *s)
s->top을 초기화 시켜준다.
5) int is_empty(LinkedStackType *s)
s->top이 NULL인지를 확인하여 스택이 비어있는 지 확인한다.
6) void push(LinkedStackType *s, element item) 
노드를 만들어서 전달받은 데이터를 넣고 stack에 추가한다.
7) element pop(LinkedStackType *s)
stack에 있는 데이터를 맨 위에서부터 꺼내고 top을 그 다음 node로 바꿔준다.
8)element peek(LinkedStackType *s)
스택에서 데이터를 삭제하지 않고 맨 위에 데이터를 반환한다.
9) int main()
스택을 선언 후 초기화시킨다. push 함수로 1,2,3을 순서대로 넣고 pop 함수로 꺼내준다.

2. Assignment04_code_2_2171023_Yelin_Song.cpp
C language로 작성된 코드이다. 큐를 이용하여 은행원이 2명이라고 가정하고 시뮬레이션하였다.

1) typedef struct element 
customer의 정보를 담은 구조체이다. id, 도착시간, 서비스 시간이 들어있다.
2) typedef struct QueueType 
배열을 이용한 큐와 front, rear이 담긴 구조체이다.
3) double random() 
랜덤 값을 반환하는 함수이다.
4) 전역 범위에서 선언된 변수들
main함수를 포함한 모든 함수에서 사용하기 위해 전역에서 선언하였다.
5)int is_empty(QueueType * q)
큐가 비어있는 지 확인한다.
6) int is_full(QueueType * q)
큐가 full인지 확인한다.
7) void enqueue(QueueType * q, element item)
큐에 데이터를 넣는다.
8) element dequeue(QueueType * q)
큐에서 데이터를 꺼낸다.
9) int is_customer_arrived()
랜덤 값이 설정한 값보다 작으면 손님이 들어왔다고 가정하는 함수이다.
10) void insert_customer(int arrival_time)
customer의 정보를 구조체에 저장하고 큐에 넣는다
11) int remove_customer()
큐에서 데이터를 꺼내서 service time 등을 계산한다,
12) void print_stat()
최종적으로 서비스 받은 고객 수, 기다린 시간, 기다린 시간 시간 평균 값 등을 리턴한다.