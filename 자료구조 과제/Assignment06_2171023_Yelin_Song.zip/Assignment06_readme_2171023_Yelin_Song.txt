1. Assignment06_code_1_2171023_Yelin_Song.cpp
c언어로 구현한 코드이다. input data를 오름차순으로 정렬한다.
1) element delete_max_heap(HeapType *h)
root node의 데이터를 반환하고 root node를 지운다 그리고 마지막 leaf node를 root node로 올리고 child node와 비교해가며 큰 값이 윗쪽으로 올라갈 수 있게 교환한다.
2) void build_max_heap(HeapType *h)
leaf node의 parent node 부터 root node까지 child node 왼쪽,오른쪽이랑 비교해가며 데이터가 더 큰 값이면 교환한다.
3) void heap_sort(HeapType *h, element *a, int n)
build max heap 함수를 호출해서 heap을 정렬하고 delete max heap 함수로 heap을 정렬하여 배열에 저장한다.

2. Assignment06_code__2171023_Yelin_Song.cpp
c언어로 구현된 코드이다. huffman code로 인코딩하고 디코딩한다.
1) void huffman_traversal(TreeNode *node,int codes[],int top) 
자주 사용하는 데이터를 기준으로 만들어진 tree로 code word를 찾는다.
2) void huffman_encoding(char *str, bits_stream *bits_str)
huffman_traversal 함수에서 찾은 code word를 사용하여 문자열로 bit으로 바꾼다.
3) int huffman_decoding(bits_stream *bits_str, TreeNode *node, char *decoded_str)
자주 쓰는 데이터를 기준으로 만들어진 tree를 사용하여 bit을 문자열로 바꾼다.