1. Assignment09_code_1_2171023_송예린.cpp
hashing으로 데이터를 삽입,정렬,탐색하는 코드이다.
1) int transform(char *key) 
문자열을 아스키코드로 바꿔준다.
2) int hash_function(char *key) 
hash 주소를 반환한다.(table에서 몇번째)
3) void hash_chain_delete(element item, ListNode *ht[])
hash에 저장된 값 문자열을 삭제한다.
4) void hash_chain_add(element item, ListNode *ht[])
아스키코드를 기준으로 hash 주소를 구해서 hash에 문자열을 삽입한다.
5) void hash_chain_search(element item, ListNode *ht[])
찾는 문자열이 있으면 있음을 출력한다.
6) void hash_chain_print(ListNode *ht[])
hash에 저장된 문자열들을 순서대로 출력한다.

2.  Assignment09_code_2_2171023_송예린.cpp
Binary search tree를 이용해 input 값을 정렬하는 코드이다.
1)TreeNode * new_node(int item)
추가할 값의 node를 만든다.
2) TreeNode * insert_node(TreeNode * node, int key)
node를 root를 기준으로 크면 left node, 작으면 right node로 이동 후 null인 node에 저장한다.
3) void print_node(TreeNode *node)
저장된 node를 Travelsal로 출력한다. 