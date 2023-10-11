1. Assignment08_code_1_2171023_송예린.cpp
2가지 방식으로 min heap을 구현하는 코드이다.
1) void Decrease_key_min_heap(int A[],int i,int key)
바뀐 node를 기준으로 parent와 비교해가며 min heap을 만든다.
2) void Increase_min_heap(int A[], int i, int key)
바뀐 node를 기준으로 child와 비교해가며 min heap을 만든다. 

2. Assignment08_code_2_2171023_송예린.cpp
prim algorithm을 min heap을 이용해서 구현한 코드이다.
1) typedef struct element
연결된 vertex들도 key값과 함께 저장한다.
2) void build_min_heap(HeapType *h)
만들어진 heap을 min heap 형태로 만든다. 
3) element delete_min_heap(HeapType *h)
root node를 반환하고 마지막 leaf node를 root node로 올려서 min heap으로 만든다.
4) int get_min_vertex(HeapType *A,int n)
min value를 heap에서 꺼낸다.
5) void prim(HeapType *A,int s, int n)
모든 vertex에 무한대 숫자를 넣고 edge와 비교해가며 더 작은 값을 vertex에 넣는다. 이때 heap을 사용함.