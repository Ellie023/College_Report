1. Assignment03_code_2_2171023_송예린.c
C language로 작성된 코드이다. 연결리스트를 활용하여 집합 a,b를 만들고 원소들을 오름차순으로 넣는다. 그리고 집합 c에 a,b 원소들을 오름차순으로 저장한다. 
1) typedef struct  ListNode
data와 node의 link를 저장할 구조체 ListNode를 만든다.
2)ListNode *insert_node(ListNode *head, int *data)
전달받은 data를 연결리스트 앞에 삽입하는 함수이다.
new node p를 만들어서 전달받은 data 값을 넣고 전달받은 head node 앞에 삽입하고 head 값을 return 해준다.
3) ListNode *insert_last(ListNode *head, int *data)
전달받은 data 값을 연결리스트에 뒤에 삽입하는 함수이다. 전달받을 data 값을 넣을 node p를 만들고 data 값을 넣어준다. 마지막 노드 값을 반복문을 통해서 찾아주고 마지막 노드 link에 p를 넣는다 
4) ListNode *Merge(ListNode *a,ListNode *b)
집합 a,b의 data 값을 오름차순으로 집합 c에 병합하는 함수이다. 둘 중 하나가 비었다면 다른 집합을 모두 c에 그대로 넣어준다. 집합 a,b의 data 값을 비교해서 큰 값을 집합 c의 마지막 노드와 연결시켜주고 집합 c에 넣은 집합의 연결리스트만 다음으로 넘겨주며 계속 반복하여 비교한다.
둘 중 하나가 NULL이면 반복문을 멈추고 NULL이 아닌 집합을 비교 연산이 수행  안 된 값만 c에 넣어준다.  
5) 전달받은 연결리스트의 data 값을 순서대로 출력하는 함수

2. Assignment03_code_3_2171023_송예린.c
C language로 작성된 코드이다. 리스트 ADT를 만들고 연산할 때마다 호출해서 사용한다.
1) typedef struct  ListNode
data와 node의 link를 저장할 구조체 ListNode를 만든다.
2)typedef struct ListType
연결리스트의 첫 노드와 마지막 노드와 노드의 개수를 저장한다.
3) void init(ListType *plist)
리스트를 초기화하는 함수이다.
4) void error(char *message)
오류처리 함수이다. 오류 메시지를 출력하고 종료한다.
5) int is_empty(ListType *list)
list가 비어있으면 1을 아니면 0을 반환한다.
6) void insert_node(ListType *list, ListNode *p, ListNode *node)
list p 다음 위치에 new node를 삽입한다.
7) void add_first(ListType *list,int data)
new node를 만들어서 전달받은 data를 넣고 list의 가장 앞에 삽입한다.
8) void add_last(ListType *list,int data)
new node를 만들어서 전달받은 data를 넣고 list의 가장 뒤에 삽입한다.
9) ListNode *get_node_at(ListType *list, int pos)
list에서 pos 위치의 node를 반환한다.
10) void add(ListType *list, int position,element data)
position(int 형태)번째 위치에 전달받은 data 값을 넣은 node를 삽입한다.
11)  void add(ListType *list, int position,element data)
12) void remove_node(ListType *list, ListNode *p, ListNode *removed)
p 다음 위치에 removed를 제거하는 함수이다.
13) void delete(ListType *list, int pos)
pos번째 node를 제거하는 함수
14) void delete_first(ListType *list)
list의 first node를 삭제하는 함수
15) void delete_last
list의 last node를 삭제하는 함수
16) void display(ListType *list)
list의 data 값을 차례대로 출력하는 함수
17) int is_in_list(ListType *list, int item)
list에서 item이라는 data를 가지고 있는 지 검사하는 함수이다.
18) element get_entry(ListType *list,int pos)
list의 pos번째 data를 반환하는 함수

