from math import *
import sys

# 세그먼트 트리 초기화
def init_tree(node, start, end):
    if start == end:
        tree_min[node] = arr[start]
    else:
        mid = (start + end) // 2
        tree_min[node] = min(init_tree(node*2, start, mid), init_tree(node*2+1, mid+1, end))

    return tree_min[node]

# 최솟값 쿼리
def query(node, start, end, left, right):
    if start > right or end < left:
        return 1000000001
    if left <= start  and end <= right:
        return tree_min[node]
    else:
        mid = (start + end) // 2
        return min(query(node*2, start, mid, left, right), query(node*2+1, mid+1, end, left, right))

# main
n, m = map(int, sys.stdin.readline().split()) # 빠른 입력을 위해서 input() 대신 sys.stdin.readline()을 쓴다
arr = []
for i in range(n):
    arr.append(int(sys.stdin.readline()))

# 세그먼트 트리 사이즈 계산
h = int(ceil(log2(n+1))) # 트리의 높이 (root의 높이는 0)
ts = 1 << (h+1) # 트리의 총 노드개수
tree_min = [0 for i in range(ts)]

init_tree(1,0,n-1)

for i in range(m):
    a, b = [int(x) for x in sys.stdin.readline().split()]

    # 주어지는 a, b는 idx가 아니라 번째수임을 주의할 것
    print(query(1,0,n-1,a-1,b-1))