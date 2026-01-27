# 使用邻接矩阵表示一个无向图
# 顶点： 0-A, 1-B, 2-C
# 边： A-B, A-C

V = 3  # 顶点数
adj_matrix = [[0] * V for _ in range(V)]

# 添加边 A-B (0-1)
adj_matrix[0][1] = 1
adj_matrix[1][0] = 1  # 无向图需要设置对称位置
# 添加边 A-C (0-2)
adj_matrix[0][2] = 1
adj_matrix[2][0] = 1

print("邻接矩阵：")
for row in adj_matrix:
    print(row)
# 输出：
# [0, 1, 1]
# [1, 0, 0]
# [1, 0, 0]

# 使用邻接表（字典+列表）表示同一个无向图
adj_list = {
    'A': ['B', 'C'],  # A 连接着 B 和 C
    'B': ['A'],       # B 连接着 A
    'C': ['A']        # C 连接着 A
}

print("邻接表：")
for vertex, neighbors in adj_list.items():
    print(f"{vertex}: {neighbors}")
    

from collections import deque
#图的遍历算法
# 广度优先
def bfs(graph, start):
    """使用 BFS 遍历图，返回访问顺序"""
    visited = set([start])  # 记录已访问顶点
    queue = deque([start])  # 初始化队列
    result = []             # 存储访问顺序

    while queue:
        vertex = queue.popleft()
        result.append(vertex)
        # 遍历当前顶点的邻居
        for neighbor in graph[vertex]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
    return result

# 测试数据
test_graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

print("BFS 遍历顺序（从A开始）:", bfs(test_graph, 'A'))
# 输出可能是: ['A', 'B', 'C', 'D', 'E', 'F']

#深度优先
def dfs_recursive(graph, vertex, visited=None, result=None):
    """使用递归实现 DFS"""
    if visited is None:
        visited = set()
    if result is None:
        result = []

    visited.add(vertex)
    result.append(vertex)

    for neighbor in graph[vertex]:
        if neighbor not in visited:
            dfs_recursive(graph, neighbor, visited, result)
    return result

print("DFS 遍历顺序（从A开始）:", dfs_recursive(test_graph, 'A'))
# 输出可能是: ['A', 'B', 'D', 'E', 'F', 'C']